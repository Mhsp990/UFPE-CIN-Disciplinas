#Strategy Pattern
#Em resumo : É basicamente usar composition para que o comportamento do objeto mude baseado em qual objeto está no composition.
#Portanto, o objeto "principal" só faz objeto.meu_composition.metodo(), sem se importar com o que tem dentro.
#E a depender de quem é o objeto "meu_composition", o comportamento muda.
#Veja o exemplo abaixo resumido e talvez faltando coisas:

#O comportamento de robo dependerá do tipo de objeto que ocupa seu atributo (composition) "estrategia".
#Motivo : a função "mover" deles tem assinaturas similares, mas comportamentos diferentes.
class EstrategiaPadrao:
    #Estrategia "1"
    def mover(self, robo):
        return robo.avancar()


class EstrategiaZigzag:
    #Estrategia "2"
    def __init__(self, periodo=2):
        self.periodo = periodo
        self.passos_dados = 0

    def mover(self, robo):
        if self.passos_dados > 0 and self.passos_dados % self.periodo == 0:
            lado = "DIR" if (self.passos_dados // self.periodo) % 2 else "ESQ"
            robo.girar(lado)
        moveu = robo.avancar()
        if moveu:
            self.passos_dados += 1
        return moveu


class Robo:
    LADO_GRADE = 10
    _registro = {}

    def __init_subclass__(cls, categoria="geral", **kwargs):
        super().__init_subclass__(**kwargs)
        Robo._registro[cls.__name__] = cls
        cls.categoria = categoria

    def __init__(self, nome, x=0, y=0, direcao=Direcao.LESTE, obstaculos=None, estrategia=None):
        self.nome = nome
        self.x = x
        self.y = y
        self.direcao = direcao
        self.obstaculos = obstaculos if obstaculos is not None else {}
        self.estrategia = estrategia if estrategia is not None else EstrategiaPadrao()
        self._historico = []

    def mover(self):
        return self.estrategia.mover(self) 
    #Portanto, usando composition + strategy, é possível alterar o comportamento a qualquer momento apenas trocando o objeto em estrategia por outro (válido)

print(EstrategiaPadrao.__bases__)


#Command Pattern
#O padrão command é conhecido por transformar uma ação (normalmente específica) em um objeto.
#Tendo como exemplo o robo, transformarias a ação de "mover" em sua própria classe e, lá dentro, fariamos o método que realmente move o robo.
#Como "contrato", tais comandos normalmente possuem os métodos "execute" e "undo", que fazem e desfazem o que propõe a fazer.
#Desta forma, ao utilizar o comando, basta passar os parâmetros necessários e, depois, chamar execute.
#Além disso, para o nosso robo, nos permitira criar, por exemplo, lista de comandos, log, etc.
from abc import ABC, abstractmethod

class Comando(ABC):
    @abstractmethod #Toda classe que herdar desta classe Comando deve implementar este método.
    def executar(self, robo):
        ...

class ComandoAvancar(Comando):
    def __init__(self, passos):
        self.passos = passos

    def executar(self, robo):
        robo.avancar_n(self.passos)

    def __repr__(self):
        return f"ComandoAvancar({self.passos})"

class ComandoGirar(Comando):
    def __init__(self, lado):
        self.lado = lado

    def executar(self, robo):
        robo.girar(self.lado)

    def __repr__(self):
        return f"ComandoGirar({self.lado!r})"

#Portanto, para convertermos o texto que representa nossos comandos:
def parse_comando(texto):
    partes = texto.strip().upper().split()
    acao = partes[0]
    if acao == "AVANCAR":
        return ComandoAvancar(int(partes[1]))
    if acao == "GIRAR":
        return ComandoGirar(partes[1])
    raise ValueError(f"comando desconhecido: {texto!r}")

#Desta forma, no robo, bastaria fazer uma função que para cada comando existente na lista, comando.execute().
#(NA CLASSE ROBO)
def executar(robo, comandos):
    for texto in comandos:
        cmd = parse_comando(texto)
        cmd.executar(robo)
        # TODO: guarde cmd em robo._historico
        robo._historico.append(cmd)
        ...

#Como temos um historico de comandos, torna-se fácil DESFAZER o que foi feito.
#Para isso, basta executar o comando "undo" de cada elemento existente no historico.
#Além disso, permite repetir os mesmos passos para outro robo.


#Factory Pattern
#O Factory Pattern centraliza a criação de objetos, evitando que o código precise conhecer diretamente qual classe concreta deve ser instanciada. 
# Em vez de fazer RoboVeloz(...), por exemplo, você pode pedir à fábrica algo como criar_robo("veloz"), 
#e ela decide qual classe criar. Isso facilita trocar ou adicionar tipos de objetos sem espalhar a lógica de criação pelo código.
#Atualmente, usando metaprogramação, cada classe de robo se registra automaticamente em Robo._registro usando o __init_subclass()
#O método da classe Robo "criar_robo" usa essa catalogo para decidir qual classe a nova instância de robo será a partir do seu nome.

class RoboVeloz(Robo, categoria="ofensivo"):
    pass


class RoboExplorador(Robo, categoria="reconhecimento"):
    pass


def criar_robo(tipo_nome, nome, **kwargs):
    classe = Robo._registro.get(tipo_nome)  #By default, default value if key does not exist is None
    if classe is None:
        raise ValueError(f"tipo desconhecido: {tipo_nome!r}")
    return classe(nome, **kwargs)


r = criar_robo("RoboVeloz", "Speedy")
print(r.nome, r.categoria) # Speedy ofensivo


#Complementando:
FABRICA_ESTRATEGIAS = {
    "padrao": EstrategiaPadrao,
    "zigzag": EstrategiaZigzag,
    #"vaivem": EstrategiaVaivem, #Not implemented here
}


def criar_robo_configurado(tipo_nome, nome, estrategia_nome="padrao", **kwargs):
    classe_estrategia = FABRICA_ESTRATEGIAS.get(estrategia_nome)
    if classe_estrategia is None:
        raise ValueError(f"estrategia desconhecida: {estrategia_nome!r}")
    robo = criar_robo(tipo_nome, nome, **kwargs)
    robo.estrategia = classe_estrategia() 
    return robo


r2 = criar_robo_configurado("RoboExplorador", "Scout", estrategia_nome="zigzag")
print(type(r2.estrategia).__name__) #EstrategiaZigzag
print(EstrategiaZigzag) # <class '__main__.EstrategiaZigzag'>
print(type(EstrategiaZigzag)) #<class 'type'>


#Singleton:
#Neste padrão, a criação de um objeto de uma determina classe só permite existir UM deste ativo a todo momento.
#Ou seja : Tentar criar um novo retorna um já existente, caso existe. Portanto, todo o "código" acessa a mesma instância.
#Desta forma, a classe sempre sabe qual sua instância atual.
class Configuracao:
    _instancia = None

    def __new__(cls): #Chamado toda vez que que um OBJETO desta classe é instanciado.
        if cls._instancia is None: #Se já não existir uma instância, crie.
            cls._instancia = super().__new__(cls)

        return cls._instancia #Retorne a instância já existente.


config1 = Configuracao()
config2 = Configuracao()

print(config1 is config2)

#Observer Pattern
#Este daqui equivale ao signals do godot : Quando o objeto 1, que chamaremos de observado, faz alguma coisa, este "emite um sinal".
#Quando esta ação de interesse ocorre, todos os n-objetos OBSERVADORES reagem, cada um fazendo alguma coisa (ou nada).
#Portanto, para facilitar nossa vida no python, a única coisa que precisamos é:
#No Observado (objeto 1), ter uma lista de observadores.
#Quando algo ocorrer, chamar um método específico NOS OBSERVADORES a partir do objeto 1.
#       Neste caso, passamos certas coisas como parametro, inclusive o "tipo" de sinal, para que o observador saiba se interessa a ele ou não.
#O observador, ao ter seu método "reagir" gatilhado pelo objeto 1, simplesmente analisa o "tipo" e decide como reagir, recebendo também
#várias informações que foram enviadas como argumentos (exemplo : nivel de bateria, etc).
#Exemplos pro robor:  Avisar quando bater em uma parede, avisar quando o nível de bateria muda ou fica crítica, etc.


#Como funciona no python, de maneira simplificada:
#O sujeito que será observado guarda uma lista de observadores e possui um método chamado "notificar".
#Quando este método é chamado, todos os OBSERVADORES na lista executam, através do sujeito (objeto observado), o método "atualizar".
#O método atualizar dos observadores receberá os argumentos passados pelo sujeito e, dai, faz o que querem fazer (inclusive nada).
#OBS : Para poder diferenciar qual o "tipo de aviso", neste caso foi usado um campo padrão para distinguir o tipo de mensagem
#       portanto, dentro do observador, ele verifica este tipo e muda seu comportamento de acordo.
class Sujeito:
    def __init__(self):
        self._observadores = []

    def adicionar_observador(self, observador):
        self._observadores.append(observador)

    def remover_observador(self, observador):
        self._observadores.remove(observador)

    def notificar(self, **dados):
        for obs in self._observadores:
            obs.atualizar(**dados)


class Observador:
    def atualizar(self, **dados):
        raise NotImplementedError


class PrintObservador(Observador):
    def __init__(self, nome):
        self.nome = nome

    def atualizar(self, **dados): #Importante : Use kwargs, para deixar genérico
        print(f"{self.nome} recebeu: {dados}")

s = Sujeito()
s.adicionar_observador(PrintObservador("Obs1")) #Neste caso, estamos criando o objeto "ao mesmo tempo" que o passamos. Mas não precisa ser assim.
s.adicionar_observador(PrintObservador("Obs2"))

#Neste caso, irá sair duas saídas, pois existem dois observadores reagindo 
s.notificar(evento="teste", valor=42) 
#Obs1 recebeu: {'evento': 'teste', 'valor': 42}
#Obs2 recebeu: {'evento': 'teste', 'valor': 42}


#Portanto, é possível fazer o sistema reagir a eventos. Por exemplo, é possível implementar um logger:
class Logger(Observador):
    def __init__(self):
        self.eventos = []

    def atualizar(self, **dados): 
        self.eventos.append(dados)


log = Logger()
s2 = Sujeito()
s2.adicionar_observador(log)
s2.notificar(evento="primeiro")
s2.notificar(evento="segundo")
print(log.eventos) # [{'evento': 'primeiro'}, {'evento': 'segundo'}] #Uma lista dos eventos (e seus tipos)


#Desta forma, pode-se dizer que o sujeito deve ter os seguintes mecanismos e atributos:
#   Atributo "observadores", contendo a lista de todos os observadores inscritos
#   Método Notificar(self, tipo_evento, **dados). 
#           Este método irá pecorrer a lista de observadores, ativando os método "atualizar" deles, passando tipo_evento e **dados como argumentos.
#   Método adicionar_observador(self, obs) : Recebe um objeto para ser adicionado a lista de observadores.
#Portanto, quando alguma coisa no sistema ocorrer, basta o sujeito usar o método notificar.
#Exemplo : Colocar no setter de nivel_bateria para usar notificar toda vez que o valor for alterado (ou alcançar valor crítico)

#E o sujeito deve ter o método "atualizar", preparado para receber(self, tipo_evento, **dados) (self, nesse caso, é o próprio observador).
#OBS: É comum, no sujeito, criar uma chave para si mesmo, a fim de passar uma referência de si.



#State Pattern
#Isto daqui é basicamente o strategy pattern com composition.
#De tal forma que funciona basicamente assim:
#O objeto possui um estado. Cada estado é uma classe com os mesmos métodos (exemplo : execute(), mover(), avisar(), etc)
#A depender de qual estado o objeto robo possui, ao fazer robo.avisar() (por exemplo), o comportamento muda.

#Veja o exemplo:
class ModoOperacao:
    def mover(self, robo):
        raise NotImplementedError


class ModoExplorando(ModoOperacao):
    def mover(self, robo):
        return robo.avancar()


Robo.mover = lambda self: self.modo.mover(self)
robo3 = Robo("Optimus", x=5, y=5)
robo3.modo = ModoExplorando()
robo3.mover()
print(robo3.x, robo3.y)
