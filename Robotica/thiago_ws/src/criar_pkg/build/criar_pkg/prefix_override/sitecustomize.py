import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/mhsp/Documents/thiago_ws/src/criar_pkg/install/criar_pkg'
