from typing import Dict, List, Union

from library import SIGNALS, free_2d_array, list_processes, send_signal


def call_list_process(type: int) -> Dict[str, Union[str, List[str]]]:
    if type not in [0, 1]:
        return {'Error': 'Invalid process type'}

    processes = list_processes(type)
    if processes is None:
        return {'Error', 'An error occured while fetching the processes'}

    formatted_processes = []
    counter = 0
    for process in processes:
        if process is None:
            break
        splitted_list = process.decode('utf-8').split()
        if len(splitted_list) < 5:
            continue
        formatted_processes.append(splitted_list[:5])
        formatted_processes[counter].append(
            ' '.join(splitted_list[5:]))
        counter += 1

    free_2d_array(processes)

    return {'process': formatted_processes}


def call_send_signal(pid: int, signal: int) -> Dict[str, str]:
    if pid <= 0:
        return {'Error': 'Invalid PID'}

    if signal not in SIGNALS.values():
        return {'Error': 'Invalid Signal'}

    response = send_signal(pid, signal)
    if response == 1:
        return {'Success': 'Signal sent successfully'}
    return {'Error': 'An error occured while sending the signal'}
