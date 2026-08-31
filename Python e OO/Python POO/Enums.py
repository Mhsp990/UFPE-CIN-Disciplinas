#ENUMS
#Enum é uma forma de criar um conjunto de valores constantes e nomeados.
#Bastante útil quando certas variáveis possuem um conjunto limitado de opções.
#Por baixo dos panos, funciona similar a um dicionario, tendo chave : valor.
#É necessário importar para utilizar e, depois, criar uma classe que herda de Enum para representar o seu Enum.
#OBS : É possível usar o "valor" atribuido ao ENUM para "procurar" ele. Veja o exemplo de Direcao.
#OBS 2 : Embora seja uma classe, normalmente NÃO se cria objetos dela. Ou seja, usa a classe diretamente.

from enum import Enum, auto #auto é usado para atribuir automaticamente um valor. Como se fosse uma pk incremental.

class Prioridade(Enum):
    BAIXA = auto()
    MEDIA = auto()
    ALTA = auto()

class MeuOutroEnum(Enum):
    BAIXA = 0

p = Prioridade.ALTA
print(p) #Sai, literalmente, a chave. Ou seja: "Prioridade.Alta"
print(p.name, p.value) #ALTA 2, ou seja, funciona similar a um dicionario.
print((Prioridade.ALTA == Prioridade.ALTA)) #Sai true. Não está comparando os valores, está comparando o atributo. Ou seja, são o mesmo atributo.
print((Prioridade.BAIXA == MeuOutroEnum.BAIXA)) #FALSE, pois embora tenham o mesmo valor, são enums diferentes
print(Prioridade.ALTA == "ALTA") #False.

print("=================================================")

class Direcao(Enum):
    LESTE = (1,0)
    NORTE = (0,1)
    OESTE = (-1, 0)
    SUL = (0, -1)

    def eh_horizontal(self):
    #Lembrando que não é necessário criar instancias da classe para usar o enum.
    #Neste caso, NÃO se usa a classe.metodo direto. Ao invés disso, usa-se Direcao.Leste.eh_horizontal()
        dx, dy = self.value #Funciona. Neste caso, self seria, por exemplo, Direcao.Leste. Em seu campo "value" está a tupla (1,0)
    #                           Lembrando : Sem o .value, não ia acessar o valor associado.
        return dx != 0

    
    def virar_esquerda(self):
        ordem = [Direcao.LESTE, Direcao.NORTE, Direcao.OESTE, Direcao.SUL]
        return ordem[(ordem.index(self) + 1) % 4]

    def virar_direita(self):
        ordem = [Direcao.LESTE, Direcao.NORTE, Direcao.OESTE, Direcao.SUL]
        return ordem[(ordem.index(self) - 1) % 4]
    

print(Direcao.LESTE) #Direcao.Leste
print(Direcao.LESTE.value) #(1,0)
dx, dy = Direcao.LESTE.value 
print(dx, dy) #1 0

#IMPORTANTE
print(Direcao((1, 0))) # Direcao.Leste : Neste caso, usou-se o valor para procurar o Enum relacionado.

#O exemplo anterior é bastante útil, pois é possível, por exemplo, fazer:
Direcao.LESTE.eh_horizontal()
#Ou seja, fazer ClasseEnum.ChaveEnum.metodo_da_classe()  #Neste caso, o self é a chave enum.

print(Direcao.LESTE.virar_esquerda()) #Direcao.NORTE
print(Direcao.LESTE.virar_direita()) #Direcao.SUL


#Portanto, veja o exemplo abaixo
class Robo:
    LADO_GRADE = 10

    def __init__(self, nome, x=0, y=0, direcao=Direcao.LESTE):
        self.nome = nome
        self.x = x
        self.y = y
        self.direcao = direcao

    def girar(self, lado):
        if lado == "ESQ":
            self.direcao = self.direcao.virar_esquerda()
        elif lado == "DIR":
            self.direcao = self.direcao.virar_direita()


robo1 = Robo("Wall-E")
robo1.girar("ESQ")
print(robo1.direcao) #Direcao.NORTE #Se quisesse o valor, bastaria acessar o .value.
