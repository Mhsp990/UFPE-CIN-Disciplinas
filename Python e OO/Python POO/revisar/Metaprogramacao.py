#Metaprogramação

#Módulos e Imports
#Quando você faz, por exemplo, import math, o que está acontecendo?
#Bem, começaremos pelo fato que, neste caso, math é um objeto do tipo "Module", com atributos e métodos acessíveis via notação ('.'). Portanto, ao fazer
#import math, o python está, na verdade, criando ou recuperando este objeto no escopo atual e dá um nome a ele. Todo módulo possui o seu próprio __dict__.
import math

print(type(math)) #<class 'module'>
print(math.pi) # 3.141592653589793
print(sorted(math.__dict__.keys())[:5]) #['__doc__', '__loader__', '__name__', '__package__', '__spec__'] 
print(math.__name__) # math

#Python só executa o corpo de um módulo uma por sessão do interpretador — 
# da segunda vez em diante, `import` devolve o mesmo objeto já criado, guardado num
#dicionário global chamado `sys.modules` (nome do módulo → objeto módulo). Ou seja, não da "duplicação".
import sys

print("math" in sys.modules) #True. Isto está verificando quais módulos foram adicionados ao "contexto" atual.
print(sys.modules["math"] is math) #True
print(sys.modules) #Vai printar um monte de bibilioteca, inclusive as que são importadas "implicitamente" pelo próprio python.

#Observe que, como o python executa o corpo dos modulos ao realizar o seu import, isso significa que qualquer código presente nele
#que estiver solta (sem ser def, class, etc) também será executado. Por isso, normalmente faz-se:
# if __name__ == "__main__":
#     faça algo

# Quando um arquivo é executado diretamente, o Python atribui ao `__name__` daquele módulo o valor especial `"__main__"`. 
# Quando o mesmo arquivo é importado por outro, `__name__` vira o nome do arquivo. O `if` pergunta, literalmente, 'estou sendo
# o programa principal, ou fui só importado?' — e só roda o bloco no primeiro caso.


#GETATTR e SETATTR

#__getattr__
#Por padrão, se o atributo não existir, obtêm-se o erro "AttributeError". Lembre-se : Cada objeto tem um "dicionario de atributos"
#O método __getattr__ é chamado APENAS quando a busca "normal", que olha o dicionario da instância e depois, da classe, FALHA.

# Entretanto, caso desejado, um objeto pode SOBRESCREVER o método __getattr__(self, nome_attr).
#           self : O objeto em questão.
#           nome_attr : A string que representa qual o nome do atributo.

#Ao sobrescrever este método, é possível determinar o seu comportamento ao tentar buscar QUALQUER atributo.
#Por exemplo, podemos usá-lo para calcular algo sob demanda, ao invés de ser na criação do objeto.

#Lembre-se : O método __getattr__ normalmente só é chamado se a busca pelo atributo falha.
#Neste caso, estamos definindo para esta classe "como reagir" neste caso. Ou seja, como a busca na classe e em suas instancias reagem ao NÃO encontrar.
#Veja o exemplo:
class PessoaComGetattr:
    def __init__(self, nome):
        self.nome = nome

    def __getattr__(self, nome_attr):
        return f"{nome_attr} desconhecido"


p2 = PessoaComGetattr("Ana")
print(p2.nome)      # __getattr__ NÃO é chamado — já está no __dict__ (neste caso, no dict da instância.)
print(p2.idade)      # __getattr__ é chamado — não existe em lugar nenhum (Não existe na instância atual e nem em sua classe.)---> idade desconhecido



#Agora, veja este exemplo mais completo, que irá usar o __getattr__ para interceptar qualquer chamada (que irá falhar) do tipo:
# instância.leitura_<direcao>
from enum import Enum

class Direcao(Enum):
    LESTE = (1, 0)
    NORTE = (0, 1)
    OESTE = (-1, 0)
    SUL = (0, -1)


class Robo:
    def __init__(self, x=0, y=0, obstaculos=None):
        self.x = x
        self.y = y
        self.obstaculos = obstaculos if obstaculos is not None else {}

    def __getattr__(self, nome_attr):
        #Intercepta qualquer buscar de atributo falha que tenha o formato "instancia.leitura_<direcao>".
        #Desta forma, a direcao desejada estará sendo carregada no proprio nome do atributo.

        #A linha abaixo cria uma chave NO OBJETO chamada "_cache_leituras", caso não exista. Se existir, retorna ela.
        #Isso faz com que o objeto CRIE o atributo sob demanda e, portanto, as manipulações nele irão persistir.
        #Pois em uma proxima execução, irá fazer o get de self.__dict__["_cache_leituras"], que irá retornar o objeto existente.
        #Isso possibilita evitarmos o código abaixo, caso exista no chace.
        cache = self.__dict__.setdefault("_cache_leituras", {}) #Cria um dicionario. Existirá dentro do objeto que foi passado como self.
        #Neste caso, cache é sempre atualizado a cada chamada. Cache basicamente diz se a direção desejada está livre ou não.


        if nome_attr in cache:
            return cache[nome_attr]
        if nome_attr.startswith("leitura_"): #Se iniciar com leitura, já saberemos que é pq queremos a direcao. Vamos validar agora.
            direcao_nome = nome_attr.removeprefix("leitura_").upper() #Deixa tudo maiusculo para comparar.
            try:
                direcao = Direcao[direcao_nome] #Valida a direcao.
            except KeyError:
                raise AttributeError(f"Robo não tem atributo {nome_attr!r}") from None
            dx, dy = direcao.value
            nx, ny = self.x + dx, self.y + dy
            livre = (0 <= nx < LADO_GRADE and 0 <= ny < LADO_GRADE
                     and (nx, ny) not in self.obstaculos)
            cache[nome_attr] = livre
            return livre
        raise AttributeError(f"Robo não tem atributo {nome_attr!r}")


robo1 = Robo(x=5, y=5)
print(robo1.leitura_norte)
print(robo1.leitura_sul)



#       SETATTR
#__setattr__
#Este funciona de forma OPOSTA ao __getattr__, pois o __setattr__ reage a TODA atribuição, INDEPENDENTEMENTE se tal atributo existe ou não.
#Isto pode ser usado, por exemplo, para ter um histórico de mudanças de um determinado atributo, criando-se um log.


class RoboAuditado:
    def __init__(self, x=0):
        self.x = x

    def __setattr__(self, nome_attr, valor):
        log = self.__dict__.setdefault("_log_mudancas", []) #Registra ANTES de fazer a nova atribuição
        if nome_attr != "_log_mudancas": #Evita criar um log de "si mesmo". Ainda será possível atribuir algo em _log_mudancas, pois nao damos return.
            log.append((nome_attr, valor))
        
        super().__setattr__(nome_attr, valor) #IMPORTANTE : Sempre chame o super no final.


robo3 = RoboAuditado() #Começa com valor padrão = zero
robo3.x = 1
robo3.x = 2
print(robo3._log_mudancas) #[('x', 0), ('x', 1), ('x', 2)]
#robo3._log_mudancas = 3 #Nada impede de fazer isso. Mas causaria erro em qualquer set de qualquer atributo futuro, pois tentaria dar append em um "NÃO LISTA"


#Veja, agora, este outro exemplo, que irá IGNORAR atributos que deveriam ser "ocultos" (começam com '_')
class RoboAuditadoFiltrado:
    def __init__(self, x=0):
        self.x = x
        self._interno = 0

    def __setattr__(self, nome_attr, valor):
        log = self.__dict__.setdefault("_log_mudancas", [])
        if not nome_attr.startswith("_"): #Evita escrever atributos "ocultos"
            log.append((nome_attr, valor))
        super().__setattr__(nome_attr, valor)


robo4 = RoboAuditadoFiltrado()
print(robo4._log_mudancas)




#__init_subclass__

#Este método "mágico" é gatilhado toda vez que uma SUBclasse é DEFINIDA e, portanto, antes de qualquer instância dela existir.
#Portanto, este método será definido na CLASSE MÃE.
#Exemplo de utilidade : Criar um registro de todas as subclasses existentes de uma determinada classe de forma automática (a final, é metaprogramação)
#Veja o exemplo abaixo:
class Animal:
    registrados = []

    def __init_subclass__(cls, **kwargs):
        super().__init_subclass__(**kwargs) #Sempre chame o super. Se não, o python só sobrescrever e a criação da classe não ocorre.
        Animal.registrados.append(cls) #Cria um registros de classes. (cls contém o nome dado aquela classe.)

class Cachorro(Animal):
    pass

class Gato(Animal):
    pass

print(Animal.registrados) # [<class '__main__.Cachorro'>, <class '__main__.Gato'>]

#No caso do robo, veja o próximo exemplo:
class Robo3:
    _registro = {}

    def __init_subclass__(cls, categoria="geral", **kwargs):
        super().__init_subclass__(**kwargs)
        Robo3._registro[cls.__name__] = cls  #Cria dentro do dicionario, usando o NOME DA CLASSE como chave. "RoboVeloz": <class '__main__.RoboVeloz'>
        print(f'Nome da classe é : {cls.__name__}') #Imprime o nome da classe. Neste exemplo : "RoboVeloz" (uma string). 
        cls.categoria = categoria #Cria um campo categoria, ou seja, um ATRIBUTO DE CLASSE

    def __init__(self, nome):
        self.nome = nome


class RoboVeloz(Robo3, categoria="ofensivo"):
    pass

print(Robo3._registro) # {'RoboVeloz': <class '__main__.RoboVeloz'>}
print(RoboVeloz.categoria) #ofensivo


