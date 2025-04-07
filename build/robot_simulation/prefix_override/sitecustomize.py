import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/epon/AutoDrive/autonomous_combine/install/robot_simulation'
