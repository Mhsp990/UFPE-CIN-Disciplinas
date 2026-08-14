class Termometro:
    def __init__(self, celsius = 0):
        self._celsius = celsius

     #PROPERTY : Decoretor que basicamente diz que este é um GETTER. Portanto, ao usar self.nome_metodo, executa o metodo
    #           Portanto, basicamente chama o metodo sem precisar colocar o () no final
                #IMPORTANTE : Não precisa estar associado a uma variável que já existe
    @property
    def celsius(self): #So funciona para retornar o valor. Não funciona para alterar o valor.
        return self._celsius

    @celsius.setter #Define o metodo abaixo como setter. Precisa do PROPERTY definido anteriormente.
    def celsius(self, valor): #Ao colocar com o outro atributo, vira um getter
        pass

    @property #OBSERVE que não necessita que o atributo fahrenheit exista.
    #Portanto, evite associar exclusivamente a variáveis.
    #Outro exemplo para abstrair : Ao inves de guardar idade de uma pessoa, guardar data de nascimento e 
    #usar um get para calcular baseado na data de nascimento e a atual.
    def fahrenheit(self):
        return ((self._celsius*9)/5)*1 #equacao errada
    
    #Portanto, tendo o objeto t da classe Termometro:
t = Termometro(25)
print(t.celsius) #Usa o GETTER
t.celsius = 25 # Equivale a t.celsius(25), devido ao decorator que definiu o método como setter.
print(t.fahrenheit) #Chama o metodo fahrenheit.

# OBS : Perceba que não é necessário o nome da função que contem o decorator
#possuir o mesmo nome do atributo. 
#Perceba também que voce chama o "nome do metodo" do decorator, não da variavel.



#EXEMPLO 2
class Pessoa:
    def __init__(self, nome, data_nascimento = '01/01/1970'):
        self._nome = nome
        self._data_nascimento = data_nascimento


    @property
    def idade(self):
        ano_nascimento = int(self._data_nascimento.split('/')[2])
        ano_atual = 2026
        return ano_atual - ano_nascimento


pessoa = Pessoa("Jonh test")
print(pessoa.idade) #Chama o metodo idade. Ou seja, equivale a pessoa.idade()
#pessoa.idade = 50 #NÃO É VALIDO, POIS NAO DEFINI UM SETTER





#==================================  DATA CLASS  =======================================
#OBS: Verifique as as informações ditas abaixo são válidas.
#DATA CLASS - Decorator (@dataclass)
#O decorador @dataclass do módulo nativo dataclasses cria automaticamente métodos básicos 
# e repetitivos, como o construtor __init__, a representação em texto __repr__ 
# e a comparação de igualdade __eq__, com base nas variáveis indicadas na classe.
#Ou seja, ao inves de termos que sobrescrever os metodos especiais vistos anteirormente,
#é possível apenas usar isso e, automaticamente, já é criado métodos similares para nós.
#Portanto, operações como print(objeto) funcionam exibindo todas as variaveis e seus valores
#exibidos de forma similar a um dicionario. Além disso, objeto1 == objeto2 também é implementado, etc.
#IMPORTANTE : Ai declarar variaveis da classe, é necessário "citar" os tipos.

#isso não "locka" o tipo da variavel, mas diz ao dataclass o que esperar da variavel
#RESUMO : Usar dataclass cria os metodos especiais para você, a partir das variaveis DE CLASSE.
#Recomendação : Pesquisar mais sobre isso.
#Exemplo:
from dataclasses import dataclass

@dataclass
class Pos:
    #Para funcionar adequadamente, é necessário ter variáveis DE CLASSE, para deixar explícito
    #ao data class o que esperar.
    #OBS : Embora seja "tipado" nada impede de receber outros tipos no init, por exemplo. 
    # Não causa erro neste caso

    x : int #É necessário fazer essa "tipagem" no data class. Deste jeito, não é opcional no init e deve ser passado.
    # x #Um 'x' solto assim não é aceitável.
    y : int  
    z : int = 10 #Pode e tem outro efeito : O init dessa classe terá esse atributo como valor opcional
    #               #Ou seja, o init vai ter o parametro z com valor padrão 10.
   # minha_lista : list = [] #NAO PODE, pois dataclass detecta o problema de que todas as instancias iam compartilhar a mesma lista.
#   
    #OBSERVAÇÃO : Atributos opcionais devem ser declarados por ultimo
    #Motivo : O dataclass usa a ordem dos atributos para definir a ordem dos parametros do init.


    #Portanto, é possível criar um objeto desta classe da seguinte forma:
    #objeto = (10, "aaaaa") --> (x = 10, y = "aaaa")

    #OBS: Você pode atribuir um valor diretamente sem tipagem ( ex : a = 0), mas o dataclass
    #vai assumir que o init NÃO recebe esse valor e, portanto, passar esse valor causa um erro
    #devido a quantidade de PARAMETROS no init ao tentar criar o objeto, caso seja passado.
    z = 0 #Pode, mas tem um detalhe : A função init NÃO irá esperar receber o argumento z.
    


#Argumentos opcionais para o data class
@dataclass(frozen = True)
class NomeClassTest:
    atributo1 : str
    atributo2 : int =  0 #Pode

    #minha_lista : list = [] #NÃO PODE, da erro devido ao problema citado anteirormente.
    minha_lista =  #Usa o factory, ai o init subentende que é para criar listas separadas.

#O que faz : Ao definir frozen = True, cada instancia dessa classe é IMUTÁVEL.
#Ou seja, após criar o objeto (objeto = NomeClass(atr1, atr2)), não é possível ALTERAR seus campos.
#IMPORTANTE : Na verdade, você pode manipular o objeto que o campo aponta, mas não pode ALTERAR
#para qual objeto aquele atributo aponta (ou seja, a mesma referencia).
#Portanto:
#   minha_lista = nova_lista (ou []), DA ERRO
#   minha_lista.append(algo) PODE SIM

objeto = NomeClassTest("a", 0) #Cria
objeto.atributo1 = "b" #NÃO PODE, dá erro : FRONZE INSTANCE ERROR.