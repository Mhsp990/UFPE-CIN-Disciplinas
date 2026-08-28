#Antes de começarmos, é importante entender como realmente os atributos são criados, atribuidos e acessados no python.
#Bem, a melhor maneira de começar a analogia é dizendo o seguinte :
# O python guarda, acessa e atribui todas as variaveis existentes de um objeto através de um dicionario.
#           OBS : Isso é valido para, por exemplo, classes e suas instâncias.
#Isso quer dizer que, quando você faz:

#   meu_objeto.meu_atributo = alguma_coisa

#O python estará, na verdade, fazendo algo como acessar um dict (não exatamente isso, mas apenas a analogia):

#   meu_objeto[meu_atributo] = alguma_coisa

#De forma similar:
#   meu_objeto.meu_atributo (como se fosse um get valor) 
#   equivale a acessar o "dict" meu_objeto e procurar pela chave meu_atributo

#Ao fazer meu_objeto.__dict__
#sem parenteses ()
#Você receberá um dicionario contendo todas as variaveis (atributos) existentes neste objeto.
#ATENÇÃO: Não aparecerão atributos de CLASSE, apenas de INSTÂNCIA.

#OBS: No caso de atributos de classes e atributos de instância, o python verifica primeiro o "dict"
#da instância. Se não houver o atributo "desejado", ele procura no do pai e por ai vai.
#Por isso, é possível "sobrescrever" métodos e atributos de classes.

#Portanto, é por isso que o python:
#Consegue criar variáveis a qualquer momento, e de qualquer tipo.
#Consegue atribuir novos tipos de variáveis a variáveis de outros tipos
#      Isso significa, também : tipagem dinâmica.
#Consegue "sobrescrever" atributos e métodos de classe.

#Bem, vamos colocar as mãos na massa.

#Exemplo básico inicial
class Pessoa:

    NACIONALIDADE = "Brasileira" #Atributo de classe

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

p = Pessoa("Ana", 30) 
print(Pessoa.__dict__) #Resulta em {NACILIDADE : "Brasileira"}
print(p.__dict__) # Resulta em {'nome': 'Ana', 'idade': 30}. O atributo de classe não aparece.


#======================================================================================================================#
#======================================================================================================================#
#DESCRIPTORS
#Ao invés de guardar valores comuns, a classe pode guardar UM OBJETO que sabe reagir quando as operações de leitura ou escritas
#são executadas através de magic methods. 
#__get__(self, instance, owner) é executado quando um atributo é LIDO.
#__set__(self, instance, owner) é executado quando um atributo é ESCRITO, seja criado ou sobrescrito.
#Veja o exemplo abaixo, na qual o descriptor "mora" UMA VEZ em Pessoa.__dict__, compartilhado por todas as instâncias.
#           A unica coisa que muda é o valor guardado em instance.__dict__

class Atributo:
    def __init__(self, nome):
        self.nome = nome

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return instance.__dict__[self.nome]

    def __set__(self, instance, valor):
        instance.__dict__[self.nome] = valor


class Pessoa:
    nome = Atributo("nome")
    idade = Atributo("idade")

    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade


p = Pessoa("Ana", 30)
print(p.nome, p.idade)