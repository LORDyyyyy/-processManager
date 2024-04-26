from typing import Dict, List, Union

from library import SIGNALS, free_2d_array, list_processes, send_signal


def call_list_process(type: int) -> Dict:
    """Call the list_processes function from the C shared library

    Args:
        type (int): the  type of process to list


    Returns:
        Dict: a dictionary containing the list of processes
            or an error message if an error occurred
    """
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

        try:
            if counter != 0:
                formatted_processes[counter][1] = int(
                    formatted_processes[counter][1])

                formatted_processes[counter][2] = float(
                    formatted_processes[counter][2])

                formatted_processes[counter][3] = float(
                    formatted_processes[counter][3])
        except ValueError:
            continue

        formatted_processes[counter].append(
            ' '.join(splitted_list[5:]))
        counter += 1

    free_2d_array(processes)

    return {'process': formatted_processes[1:]}


def call_send_signal(pid: int, signal: int) -> Dict[str, str]:
    """Call the send_signal function from the C shared library

    Args:
        pid: Process ID to send the signal to
        signal: Signal to send to the process.
                must be one of the signals in the SIGNALS dictionary

    Returns:
        Dict: a dictionary containing a success message
            if the signal was sent successfully
            or an error message if an error occurred
    """
    if pid <= 0:
        return {'Error': 'Invalid PID'}

    if signal not in SIGNALS.values():
        return {'Error': 'Invalid Signal'}

    response = send_signal(pid, signal)
    if response == 1:
        return {'Success': 'Signal sent successfully'}
    return {'Error': 'An error occured while sending the signal'}
