""" Tests for core/library/libprocessManger shared library"""
import ctypes

lib = ctypes.CDLL('./core/library/libprocessManger.so')

lib.send_signal.argtypes = [ctypes.c_int, ctypes.c_int]
lib.list_processes.argtypes = [ctypes.c_int]
lib.list_processes.restype = ctypes.POINTER(ctypes.c_char_p)


def test_send_signal():
    """Test send_signal

    This function tests the send_signal function
    from the libprocessManger shared library
    The function send a SIGKILL signal, equivalent to 9, which is a KILL signal
    """
    pid = int(input("PID: "))
    print(lib.send_signal(pid, 9))
    print("Signal sent to process:", pid)


def test_list_processes():
    """Test list_processes and frees the returned 2D array

    This function tests the list_processes function
    from the libprocessManger shared library
    and also frees the allocated space from the list_processes function
    using the free_2d_array function also from libprocessManger library
    """
    pro_type = int(input("Process Type(0 for USER, 1 for ALL): "))
    process_list = lib.list_processes(pro_type)

    i = 0
    while process_list[i] is not None:
        print(process_list[i].decode().strip())
        i += 1
    lib.free_2d_array(process_list)


if __name__ == "__main__":
    """Entry Point"""

    test_send_signal()
