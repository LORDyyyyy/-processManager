import ctypes

lib = ctypes.CDLL('../core/library/libprocessManger.so')

lib.send_signal.argtypes = [ctypes.c_int, ctypes.c_int]
lib.list_processes.argtypes = [ctypes.c_int]
lib.list_processes.restype = ctypes.POINTER(ctypes.c_char_p)
lib.free_2d_array.restype = None

send_signal = lib.send_signal
list_processes = lib.list_processes
free_2d_array = lib.free_2d_array

SIGNALS = {'SIGINT': 2, 'SIGQUIT': 3,
           'SIGKILL': 9, 'SIGUSR1': 10,
           'SIGSEGV': 11, 'SIGUSR2': 12,
           'SIGTERM': 15, 'SIGCONT': 18,
           'SIGSTOP': 19, 'SIGTSTP': 20
           }
