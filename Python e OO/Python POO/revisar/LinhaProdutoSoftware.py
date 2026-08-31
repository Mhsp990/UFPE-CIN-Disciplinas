#Código inicial
from enum import Enum

LADO_GRADE = 10

class Direcao(Enum):
    LESTE = (1, 0)
    NORTE = (0, 1)
    OESTE = (-1, 0)
    SUL = (0, -1)


class EstrategiaPadrao:
    def mover(self, robo):
        return robo.avancar()


class EstrategiaEsquiva:
    def mover(self, robo):
        tentativas = 0
        while not robo.sensor_frente() and tentativas < 4:
            robo.girar("DIR")
            tentativas += 1
        return robo.avancar()


class EstrategiaZigzag:
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

    def sensor_frente(self):
        dx, dy = self.direcao.value
        nx, ny = self.x + dx, self.y + dy
        return (0 <= nx < Robo.LADO_GRADE and 0 <= ny < Robo.LADO_GRADE
                and (nx, ny) not in self.obstaculos)

    def avancar(self):
        if self.sensor_frente():
            dx, dy = self.direcao.value
            self.x += dx
            self.y += dy
            return True
        return False

    def girar(self, lado):
        ordem = [Direcao.LESTE, Direcao.NORTE, Direcao.OESTE, Direcao.SUL]
        if lado == "ESQ":
            self.direcao = ordem[(ordem.index(self.direcao) + 1) % 4]
        elif lado == "DIR":
            self.direcao = ordem[(ordem.index(self.direcao) - 1) % 4]

    def mover(self):
        return self.estrategia.mover(self)


class RoboVeloz(Robo, categoria="ofensivo"):
    def avancar(self):
        moveu1 = super().avancar()
        moveu2 = super().avancar()
        return moveu1 or moveu2


class RoboExplorador(Robo, categoria="reconhecimento"):
    pass


class RoboBlindado(Robo, categoria="defensivo"):
    pass


def criar_robo(tipo_nome, nome, **kwargs):
    classe = Robo._registro.get(tipo_nome)
    if classe is None:
        raise ValueError(f"tipo desconhecido: {tipo_nome!r}")
    return classe(nome, **kwargs)


FABRICA_ESTRATEGIAS = {
    "padrao": EstrategiaPadrao,
    "esquiva": EstrategiaEsquiva,
    "zigzag": EstrategiaZigzag,
}



#Modelo de features
