# SO(3)
# • Create a rotation matrix Rx representing a π/2 rad rotation around the x axis
# • Create a rotation matrix Ry representing a π/2 rad rotation around the y axis
# • Create a rotation matrix Rz representing a π/2 rad rotation around the z axis
# • Create a rotation matrix Rxyz representing three π/2 rad rotations around the x, y and
# then z axis
# • Create a rotation matrix Rxzy representing three π/2 rad rotations around the x, z and
# then y axis

import numpy as np
import math

np.set_printoptions(precision= 4, suppress= True)

#  1 , 2 e 3
teta = (math.pi)/2
cos = math.cos(teta)
sin = math.sin(teta)

rotation_rx = np.array([ #TETA = pi/2. Não será homogenea ainda.
    [1.0,       0.0,            0.0 ],
    [0.0,       cos,            -sin],
    [0.0,       sin,            cos]
])

rotation_ry = np.array([ #TETA = pi/2. Não será homogenea ainda.
    [cos,       0.0,            sin       ],
    [0.0,       1.0,            0.0      ],
    [-sin,       0.0,           cos       ]
])

rotation_rz = np.array([ #TETA = pi/2. Perceba a semelhança com a matriz de rotação para 2d. Motivo : As rotações eram no eixo não existente 'z'
    [cos,       -sin,            0.0       ],
    [sin,        cos,            0.0       ],
    [0.0,        0.0,            1.0       ]
])

print(f'Rotacao em X é : \n {rotation_rx}')
print(f'Rotacao em Y é : \n {rotation_ry}')
print(f'Rotacao em Z é : \n {rotation_rz}')


#   4 - Criar uma matriz de rotacao xyz ---> Rotaciona na seguinte ordem : x, depois y e por fim, z.
rot_xy = np.dot(rotation_rx, rotation_ry)
rot_xyz = np.dot(rot_xy, rotation_rz)

print(f'Rotacao X-Y-Z: \n {rot_xyz}')

#  5 mesmo do anterior, mas primeiro em X, dps em Z e por fim, em Y. Resultado será diferente do anterior.
rot_xz = np.dot(rotation_rx, rotation_rz)
rot_xzy = np.dot(rot_xz, rotation_ry)

print(f'Rotacao X-Z-Y: \n {rot_xzy}')


# SE(3)
# • Create an homogenous matrix Htx representing a 1 m translation along the x axis
# • Create an homogenous matrix Hty representing a 2 m translation along the y axis
# • Create an homogenous matrix Htz representing a 3 m translation along the y axis
# • Create an homogenous matrix Ht representing three 1, 2 and 3 m translations along the
# x, y and z axis
# • Compute the new coordinates of a = [1, 0, 0] after three 1, 2 and 3 m translations along
# the x, y and z axis
# • Create an homogenous matrix Hr representing a π/2 rad rotation around the x axis
# • Compute the new coordinates of a = [1, 0, 0] after three 1, 2 and 3 m translations along
# the x, y and z axis and one π/2 rad rotation around the x axis


def matriz_translacao_xyz(tl_x: float, tl_y: float, tl_z : float):
    """
    Gera a matriz de translação homogênea 3x3 em 2D.
    Considera-se teta = 0 (cos(0)=1 e sen(0)=0).
    """
    return np.array([
        [1.0, 0.0, 0.0, float(tl_x)], 
        [0.0, 1.0, 0.0, float(tl_y)],
        [0.0, 0.0, 1.0, float(tl_z)],
        [0.0, 0.0, 0.0, 1.0] #ULTIMA LINHA NECESSARIA PARA DEIXAR HOMOGENEA. PARECE IDENTIDADE.
    ])

# 
# 1 m em x significa que o referencial dois está em P_r2 = (1.0, 0.0)
matriz_resultante_q1 = matriz_translacao_xyz(1.0, 0.0, 0.0)
matriz_resultante_q2 = matriz_translacao_xyz(0.0, 2.0, 0.0)
matriz_resultante_q3 = matriz_translacao_xyz(0.0, 3.0, 0.0)
matriz_resultante_q4 = matriz_translacao_xyz(1.0, 2.0, 3.0)




print(f'Resultado do primeiro : Matriz homogenea : \n {matriz_resultante_q1}')
print(f'Resultado do segundo : Matriz homogenea : \n {matriz_resultante_q2}')
print(f'Resultado do terceiro : Matriz homogenea : \n {matriz_resultante_q3}')
print(f'Resultado do quarto : Matriz homogenea : \n {matriz_resultante_q4}')