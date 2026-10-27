import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/mhsp/Documents/UFPE-CIN-Disciplinas/Robotica/turtlesim_ws/install/ex_controle'
