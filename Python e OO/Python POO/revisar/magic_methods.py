#__REPR__
#Normalmente, sem sobrescrever, o método __repr__, a função print(objeto) retorna uma informação "não útil" para o leitor
#humano, como por exemplo, o endereço de memória.
#O método __repr__ é utilizado para REPRESENTAR o objeto e, portanto, é mais preciso e sem ambiguidade.
#Ao sobrescrever este método, podemos definir o que será usado como REPRESENTAÇÃO, dos objetos daquela classe.
#Ou seja, o metodo magico __repr__ define, por exemplo, a representação do objeto ao fazer print(objeto).

class Posicao:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"Posicao({self.x}, {self.y})"


p1 = Posicao(3, 4)
print(p1) #Posicao(3, 4)
print([p1, Posicao(0, 0)]) #[Posicao(3, 4), Posicao(0, 0)] #Usou o Rep, pois é uma colection

#IMPORTANTE
#Coleções (listas, dicts, tuplas) sempre usam o metodo __repr__ ao invés do __str__, mesmo que possua ambos os métodos.
# Caso não esteja explicito, ele usa o da "classe objeto", que é a classe base do python (O __repr__ "normal", "inútil").

#OBS: Para representações que são uma string, coloque o !r após a variável no print.
#Exemplo: return f"Comando({self.acao!r}, {self.valor})". 
# Isto afeta a representação, para que fique entre aspas e indique que é uma string.
# A diferença é que, ao usar o !r, a variável do tipo string sai ENTRE aspas no print.
variavel_teste_1 = "texto"
print(f'{variavel_teste_1}') # texto
print(f'{variavel_teste_1!r}') #'texto'



#__STR__
#Este método é opcional e, basicamente, um __repr__, só que "human friendly".
#Quando este método existe (ou seja, está declarado / sobrescrito), print(objeto) e str(objeto) sempre utilizarão o __str__.
#Caso não exista, o fallback é o método __repr__.
#OBS : Para colections (listas, dicts, etc), o método __STR__ nunca é utilizado. Ao invés disso, sempre usam __repr__.
#Ou seja: Printar um elemento específico vai priorizar o __str__. Entretanto, printar a LISTA diretamente usa o __repr__.
lista_teste_1 = [1, 2 , 3]
print(lista_teste_1) #Usa o repr ---> [1, 2, 3] (No caso, ele tenta usar o __str__ da lista, que depois faz fallback para repr)
print(lista_teste_1[1]) #Usa o __str__ ---> 2
print( [lista_teste_1[1]] ) #Usa o repr. --->[2]

#EXEMPLO
class Robo:
    def __init__(self, nome, x=0, y=0, direcao="LESTE"):
        self.nome = nome
        self.x = x
        self.y = y
        self.direcao = direcao

    def __repr__(self):
        return f"Robo({self.nome!r}, x={self.x}, y={self.y}, direcao={self.direcao!r})"

    def __str__(self):
        return f"{self.nome} em ({self.x}, {self.y}), direção {self.direcao}"


robo1 = Robo("Wall-E")
print(robo1)
print([robo1])



#__EQ__
#Este método define o que será feito quando fizer uma comparação de igualdade.
#Mais especificamente, quando comparar o objeto da classe em questão com outro objeto (possivelmente de outra classe)
#Caso não seja sobrescrita, compara estritamente o VALOR DE MEMÓRIA dos objetos, para ver se são LITERALMENTE o mesmo (mesma ref)
#Exemplo sem sobresrever o método __eq__:
meu_robo = Robo("my robot")
meu_robo_2 = Robo("other robot")
meu_robo == meu_robo_2 #Basicamente, chama o metodo __eq__ com self = meu_robo, segundo_parametro = meu_robo_2
meu_robo == [] #segundo_parametro pode ser qualquer tipo de objeto, inclusive outra classe distinta. Util em alguns casos.


#Exemplo
class Posicao:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"Posicao({self.x}, {self.y})"

    #Neste caso, queremos que os objetos sejam iguais se, e somente se, suas coordenadas x e y forem iguais.

    def __eq__(self, outra):
        if not isinstance(outra, Posicao):
            return NotImplemented #Um tipo de "erro raise" convencional para estes casos que o eq não foi implementado para o segundo objeto.
        return self.x == outra.x and self.y == outra.y #


p1 = Posicao(3, 4)
p2 = Posicao(3, 4)
#print(p1 == p2) #Sem sobrescrever o método __eq__, retornaria false, pois são objetos diferentes (apontam para valores de memoria distintos)
print(p1 == p2)         # True — mesmo conteúdo
print(p1 == (3, 4))     # False — não quebra, graças ao isinstance




#__LEN__
#Define o que será feito quando o método len(objeto) for utilizado.
#Importante 1: Caso NÃO seja sobrescrito, usar len(objeto) resulta em erro: TypeError: object has no len()
#               Sobrescrever sem o retorno (None) resulta no mesmo erro.
#Importante 2: Caso sobrescrito, o retorno da função DEVE ser um inteiro positivo.
#Exemplo
class Caixa:
    def __init__(self):
        self.itens = []

    def __len__(self):
        #Neste caso, estamos nos aproveitando do metodo len sob uma lista que existe no nosso objeto.
        #Sem sobrescrever, imagine que o python tentaria usar o len sob o objeto em si e não saberia o que fazer.
        return len(self.itens) 


caixa = Caixa()
caixa.itens.append("parafuso")
caixa.itens.append("porca")
print(len(caixa))

#Exemplo 2
class Grade:
    def __init__(self, lado, obstaculos=None):
        self.lado = lado
        self.obstaculos = obstaculos if obstaculos is not None else {}

    def __len__(self):
        # TODO: devolva self.lado * self.lado
        return self.lado*self.lado
        pass

grade = Grade(5, {(2, 2): True})
try:
    print(len(grade))
except TypeError as erro:
    print(f"TypeError: {erro}")



#__ITER__
#Define o que será recebido ao tentar tratar o objeto como iterável. Por exemplo, ao fazer for element in object.
#Caso não seja definido, resultaria no erro : TypeError: object is not iterable
                            #Para ajudar : Quando você faz for element in lista_1, ele basicamente usa esse método mágico.
#Ao sobrescrever este método, a função DEVE devolver um ITERÁVEL.
#       Caso não seja feito isso (Por exemplo, devolver uma lista ou inteiro diretamente), resulta em : 
#                                       TypeError: iter() returned non-iterator)
#EXEMPLO
class Robo:
    DELTAS = {"LESTE": (1, 0), "NORTE": (0, 1), "OESTE": (-1, 0), "SUL": (0, -1)}

    def __init__(self, nome, x=0, y=0, direcao="LESTE"):
        self.nome = nome
        self.x = x
        self.y = y
        self.direcao = direcao
        self.trajetoria = [(x, y)]

    def __iter__(self):
        return iter(self.trajetoria) #Transforma em iteravel

    def avancar(self):
        dx, dy = Robo.DELTAS[self.direcao]
        self.x += dx
        self.y += dy
        self.trajetoria.append((self.x, self.y))


robo1 = Robo("Wall-E")
robo1.avancar()
robo1.avancar()

for pos in robo1:
    print(pos)


#Exemplo 2
class Frota:
    def __init__(self, robos):
        self.robos = robos #Lista de nomes, mas poderia ser uma lista de objetos do tipo robo.

    def __iter__(self):
        # TODO: devolva iter(self.robos)
        return iter(self.robos) 
        pass

frota = Frota(["Wall-E", "R2D2", "Bender"])
try:
    for nome in frota:
        print(nome)
except TypeError as erro:
    print(f"TypeError: {erro}")



#__GET_ITEM__