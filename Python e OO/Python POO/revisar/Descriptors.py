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
#Por isso, é possível "sobrescrever" métodos e atributos de classes, pois estes passam a existir
#no primeiro lugar de procura (na subclasse atual).

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


#IMPORTANTE : Nunca use os métodos setattr e getattr dentro dos métodos mágicos __set__ e __get__. Como estes chamam
#os métodos mágicos por baixo dos panos, isto irá calcular um loop e estouro de pilha.
#Ou seja, dentro de __get__ e __set__, sempre use o "dicionario do objeto".


class Atributo:
    def __init__(self, nome):
        self.nome = nome

    def __get__(self, instance, owner):
        if instance is None: 
            #MOTIVO : O get pode ser chamado de duas formas : Pela instancia ou pela classe.
            #Portanto, se fizerem chamando pela classe (exemplo : Pessoa.nome), instancia is None.
            #Neste caso, retorna-se o descriptor em si, ao invés do valor acessado.
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


#Perceba que, usando composition, os atributos da classe pessoa são, na verdade, um objeto (da classe Atributo).
#Portanto, usando o exemplo anterior, faz-se p.nome ou p.idade, seja para LER our ESCREVER, na verdade o que acontece
#é que está acessando o objeto do tipo Atributo e através dos métodos mágicos, a forma como o python "executa/entende" a 
#leitura (p.nome) ou escrita (p.nome = algo) está alterada e, de acordo com o definido nos métodos mágicos, escrevemos ou lemos
#está sendo feita de forma DIRETA ao dicionário do objeto em questão.
#Qual a vantagem disso? Bem, poderiamos, por exemplo, colocar restrições na escritas (como apenas objetos de um certo tipo, etc)
#e decidir como a leitura OU escrita realmente é feita. 
#Veja o exemplo abaixo, no qual implementaremos, também, uma maneira de "nomear" o descriptor.
#____________________________________________________________-
#EXEMPLO 1
class NaoNegativo:
    def __set_name__(self, owner, name):
         #Este método é chamado automaticamente pelo python quando a classe é criada.
         #Neste caso, o campo "name" recebe o nome que o objeto Sensor deu ao atributo.
         #Portanto, Evita a chance do programador escrever errado o nome ao ser passado para o init, caso usa-se o metodo anteiror.
        self.nome = "_" + name

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return instance.__dict__[self.nome]

    def __set__(self, instance, valor):
        if valor < 0: #Condição para escrita. Neste caso, não aceita valores negativos.
            raise ValueError(f"{self.nome[1:]} não pode ser negativo, recebi {valor}")
        instance.__dict__[self.nome] = valor


class Sensor:
    alcance = NaoNegativo()

    def __init__(self, alcance=1):
        self.alcance = alcance


s1 = Sensor(3)
print(s1.alcance) # 3
try:
    s1.alcance = -1 #Vai gatilhar o erro.
except ValueError as erro:
    print(f"{type(erro).__name__}: {erro}")

#____________________________________________________________-
#EXEMPLO 2
class TextoNaoVazio:
    def __set_name__(self, owner, name):
        self.nome = "_" + name

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return instance.__dict__[self.nome]

    def __set__(self, instance, valor):
        if not valor.strip():
            raise ValueError("nome não pode ser vazio")
        instance.__dict__[self.nome] = valor


class Robo:
    nome = TextoNaoVazio()

    def __init__(self, nome):
        self.nome = nome


try:
    Robo("   ")
except ValueError as erro:
    print(f"{type(erro).__name__}: {erro}") #ValueError: nome não pode ser vazio

try:
    print(Robo("Wall-E").nome) #Cria um objeto, passando nome = "Wall-E". Em seguida, já acessa seu descriptor.
except KeyError:
    print("Complete o TODO acima para ver o resultado.")


#===================================================================================================#

#Sobre properties e Descriptors
#Na verdade, property também é um descriptor. A diferença é que property é usado para UM atributo de UMA classe, enquanto que
#os descriptors pode ser REUTILIZADOS em inúmeras classes.
#Por exemplo, se eu tiver varias variaveis de inteiros NÃO negativos, basta eu usar o descriptor NaoNegativo para cada
#ao invés de criar setters e getters para cada variável da classe em questão.

#Exemplo : Coordenadas.
class Coordenada:
    def __init__(self, minimo, maximo):
        self.minimo = minimo
        self.maximo = maximo

    def __set_name__(self, owner, name):
        self.nome_publico = name
        self.nome = "_" + name

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return instance.__dict__[self.nome]

    def __set__(self, instance, valor):
        if not (self.minimo <= valor < self.maximo):
            raise ValueError(
                f"{self.nome_publico}={valor} sai da grade "
                f"({self.minimo} a {self.maximo - 1})"
            )
        instance.__dict__[self.nome] = valor


class Teste:
    x = Coordenada(0, LADO_GRADE)

    def __init__(self, x):
        self.x = x


t = Teste(3)
print(t.x) # 3
try:
    t.x = 99 #Gatilha o erro abaixo, pois está fora do range aceitado pelo set do descriptor.
except ValueError as erro:
    print(f"{type(erro).__name__}: {erro}")


#Isto resulta em uma classe mais enxuta:
class Robo:
    LADO_GRADE = 10
    x = Coordenada(0, LADO_GRADE)
    y = Coordenada(0, LADO_GRADE)

    def __init__(self, nome, x=0, y=0):
        self.nome = nome
        self.x = x
        self.y = y


robo1 = Robo("Wall-E")
print(robo1.x, robo1.y)
robo1.x = 3
print(robo1.x)
try:
    robo1.x = 99
except ValueError as erro:
    print(f"{type(erro).__name__}: {erro}")


#VEJA O PRÓXIMO EXEMPLO ABAIXO:
class Percentual:
    def __set_name__(self, owner, name):
        self.nome = "_" + name

    def __get__(self, instance, owner):
        if instance is None:
            return self
        return instance.__dict__[self.nome]

    def __set__(self, instance, valor):
        instance.__dict__[self.nome] = max(0, min(100, valor))


class Robo2:
    bateria = Percentual()

    def __init__(self, bateria=100):
        self.bateria = bateria


robo2 = Robo2(bateria=150)
print(robo2.bateria)
robo2.bateria = -30
print(robo2.bateria)