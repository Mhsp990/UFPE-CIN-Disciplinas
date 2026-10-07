import numpy as np
import math

def matriz_translacao_xy(tl_x: float, tl_y: float, teta=0):
    """
    Gera a matriz de translação homogênea 3x3 em 2D.
    Considera-se teta = 0 (cos(0)=1 e sen(0)=0).
    """
    return np.array([
        [1.0, 0.0, float(tl_x)], 
        [0.0, 1.0, float(tl_y)],
        [0.0, 0.0, 1.0] #ULTIMA LINHA NECESSARIA PARA DEIXAR HOMOGENEA. PARECE IDENTIDADE.
    ])


def matriz_rotacao(teta ):
    """
    Gera a matriz de rotacao HOMOGENEA
    """
    return np.array([
            [math.cos(teta), -math.sin(teta), 0],
            [math.sin(teta), math.cos(teta) , 0],
            [0, 0 , 1] #FICA HOMOGENEA. NECESSARIO
        ])


# def matriz_translacao_rotacao(tl_x: float, tl_y: float, teta=0.0):
#     # Aparentemente, 
#     return np.array([
#                 [math.cos(teta), -math.sin(teta), tl_x],
#                 [math.sin(teta), math.cos(teta) , tl_y],
#                 [0,                 0 ,             1] #FICA HOMOGENEA. NECESSARIO
#             ])



#A_PONTO --> Coordenadas no REFERENCIAL A
#B_PONTO --> Coordenadas no referencial B

#A_ponto =  A_TransformadaPara_B * B_Ponto

ponto_em_b1 = np.array([0.5, 0.5, 1]) #1 é por ser homogenea

teste1 =  np.dot(matriz_translacao_xy(1.0, 0.25, 0.0), ponto_em_b1)

#TESTE 2 : Descobrir um ponto que conhecido no R1, mas quer ele no R2 (referencial 2)
# Como fazer : A matriz de transformação da translação feito no teste 1 nos da a transformação de
# "ref2 para ref1", ou seja, "traduz um ponto do ref2 para o ref1".
# Portanto, precisamos fazer o inverso. Isso pode ser obtido ao, simplesmente, pegar a inversa da transformada obtida
# no teste 1. Portanto, o calculo fica : B_PONTO = inversa(matriz_translacao_xy(1.0, 0.25, 0.0)) * A_PONTO
# OBS : Como nao tem rotação, tanto faz ser inversa ou transposta
# OBS 2 : A distancia (translacao) entre o R1 e R2 é o mesmo do Teste 1 --> r2 (origem de r2) está em 1.0, 0.25 no ref1.
ponto_em_a2 = np.array([0.5, 0.5, 1])
matriz_tl = matriz_translacao_xy(1.0, 0.25)
matriz_tl = np.linalg.inv(matriz_tl)
resultado_teste2 = np.dot(matriz_tl,ponto_em_a2)


#TESTE 3 (Prestar atenção neste, pois estes tipos com rotacao são faceis de errar.)
# Lembre-se Transladar primeiro e dps rotacionar é diferente de rotacionar primeiro e depois transladar.
# Neste caso, convsideramos que foi translação primeiro e dps rotação
# No caso de braços roboticos: Normalmente, primeiro é rotação (do motor), dps translação.
# Mesma ideia do teste 1 : O r2 está em x1 = 1.0 e y1= 0.25, mas possui um 45 graus de inclinação com relação a R1.
# Portanto, desta vez, o teta não é zero.
# Conhece o ponto em R2 : P = 0.5, 0.5
# Ponto_em_R1 = (matriz_translacao * matriz_rotacao)[Transformada de R2 para R1]  *ponto_em_r2.
# Ou seja, a "transformada final" de R2 para R1 é feita da seguinte forma: T = MatrizTranslacao * MatrizRotacao
ponto_em_b3 = np.array([0.5, 0.5, 1])
matriz_translacao = matriz_translacao_xy(1.0, 0.25)
matriz_rotacao = matriz_rotacao(math.radians(45.0))
matriz_transformada = np.dot(matriz_translacao, matriz_rotacao)
resultado_teste3 = np.dot(matriz_transformada, ponto_em_b3)



#O TESTE 4 É A MESMA IDEIA E MESMOS VALORES, MAS AGORA O PONTO É NA REFERENCIA 1.
#Assim como no teste 2, iremos usar a inversa da matriz resultante.
ponto_em_a4 = np.array([0.5, 0.5, 1])
matriz_resultante = np.linalg.inv(matriz_transformada)
resultado_teste4 = np.dot(matriz_resultante, ponto_em_a4)


print(f'Resultado do primeiro é: \n {teste1}')
print(f'Resultado do segundo é: \n {resultado_teste2}')
print(f'Resultado do terceiro é: \n {resultado_teste3}')
print(f'Resultado do quarto é: \n {resultado_teste4}')


