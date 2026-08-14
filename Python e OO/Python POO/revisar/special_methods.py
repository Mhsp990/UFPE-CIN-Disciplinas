#OBS : Coleções (listas, dicts, tuplas) sempre usam o metodo __repr__ ao invés do str. Caso não esteja explicito, ele usa o da "classe objeto", que é
#a classe base do python.
#Ou seja, o metodo magico __repr__ define, por exemplo, a representação do objeto ao fazer print(objeto).
#obs: Para representações que são uma string, coloque o !r após a variável no print.
#Exemplo: return f"Comando({self.acao!r}, {self.valor})". Caso o contrário, o sistema (computador) não entende bem.
class Posicao:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"Posicao({self.x}, {self.y})"


p1 = Posicao(3, 4)
print(p1) #Posicao(3, 4)
print([p1, Posicao(0, 0)]) #[Posicao(3, 4), Posicao(0, 0)] #Usou o Rep, pois é uma colection


