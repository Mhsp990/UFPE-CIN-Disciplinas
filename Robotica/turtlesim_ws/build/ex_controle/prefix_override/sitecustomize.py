import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/mhsp/Desktop/disciplina_robotica/turtlesim_ws/install/ex_controle'
