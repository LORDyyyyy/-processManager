import tkinter as tk
from typing import Dict, List, Union

import ttkbootstrap as tb
from call_c_functions import call_list_process, call_send_signal
from library import SIGNALS
from ttkbootstrap.dialogs import Messagebox
from ttkbootstrap.tableview import Tableview

PROCESS_TYPE = {'User': 0, 'All': 1}


class ProcessManager():

    def __init__(self, root):
        self.root = root
        self.root.title('Process Manager')
        self.root.geometry('1300x700')

        self.colors = self.root.style.colors

        self.header_frame = tb.Frame(self.root)
        self.header_frame.pack(padx=10, fill=tk.X)

        self.table_frame = tb.Frame(self.root, bootstyle='info')
        self.table_frame.pack(fill=tk.BOTH, expand=True, padx=10)

        self.pro_type_var = tk.StringVar()
        self.pro_type_var.set('User')

        self.pro_refrech_button = tb.Button(self.header_frame,
                                            text="Refresh",
                                            command=lambda: self.update_table_date(),
                                            bootstyle="info")

        self.pro_type_menu = tb.Menubutton(self.header_frame,
                                           text='Type',
                                           textvariable=self.pro_type_var,
                                           bootstyle="info")
        self.pro_type_insied_menu = tb.Menu(self.pro_type_menu)

        for index, x in enumerate(['User', 'All']):
            self.pro_type_insied_menu.add_radiobutton(label=x,
                                                      variable=self.pro_type_var,
                                                      command=lambda: self.update_table_date(),
                                                      font=('Arial', 14),)
        self.pro_type_menu['menu'] = self.pro_type_insied_menu

        self.pro_type_label = tb.Label(
            self.header_frame, text='Process Type',
            bootstyle="info", font=('', 18))

        self.pro_type_label.pack(side=tk.LEFT, padx=10, pady=10)
        self.pro_type_menu.pack(side=tk.LEFT, padx=10, pady=10)
        self.pro_refrech_button.pack(side=tk.LEFT, padx=10, pady=10)

        self.do_treeview()
        self.update_table_date()

        self.do_signal()

    def update_process_type(self, type: int) -> Union[List, None]:
        """Get a new version of the process list based on the type

        Args:
            type: the type of process to list

        Returns:
            List: a list of processes or None if an error occurred
        """
        self.pro_type_menu.config(text=self.pro_type_var.get())
        process_list = call_list_process(type)
        if 'Error' in process_list.keys():
            Messagebox.showerror('Error', process_list['Error'])
            return
        # print(process_list)
        # print(self.pro_type_var.get())
        return process_list

    def do_treeview(self) -> None:
        """Create the tableview widget to display the process list
        """
        process_list = self.update_process_type(
            PROCESS_TYPE[self.pro_type_var.get()])

        if process_list is None:
            return
        self.columns = ['USER', 'PID', '%CPU', '%MEM', 'TIME', 'COMMAND']
        self.columns = [{'text': x, "stretch": False} for x in self.columns]

        self.table = Tableview(self.table_frame,
                               coldata=self.columns,
                               rowdata=process_list['process'],
                               searchable=True,
                               stripecolor=(self.colors.light, None),
                               autofit=True,
                               autoalign=True,
                               height=10
                               )
        self.table.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

    def update_table_date(self) -> None:
        """Update the table data
        based on the process type on change of the process type
        or refresh button click
        """
        process_list = self.update_process_type(
            PROCESS_TYPE[self.pro_type_var.get()])
        if process_list is None:
            return
        self.table.build_table_data(
            coldata=self.columns, rowdata=process_list['process'])

    def do_signal(self):
        # PID input Row
        third_row_frame = tk.Frame(self.root)
        third_row_frame.pack(pady=10)

        tk.Label(third_row_frame, text="Enter PID:").pack(side=tk.LEFT)
        self.pid_entry = tk.Entry(third_row_frame)
        self.pid_entry.pack(side=tk.LEFT)

        # Signal Type Dropdown Row
        fourth_row_frame = tk.Frame(self.root)
        fourth_row_frame.pack(pady=10)

        tk.Label(fourth_row_frame, text="Signal Type:").pack(side=tk.LEFT)
        self.signal_type = tk.StringVar()
        self.signal_type.set("SIGKILL")
        signal_dropdown = tb.Combobox(
            fourth_row_frame, textvariable=self.signal_type)
        signal_dropdown['values'] = tuple(SIGNALS.keys())
        signal_dropdown.pack(side=tk.LEFT)

        # Send Signal Button Row
        fifth_row_frame = tk.Frame(self.root)
        fifth_row_frame.pack(pady=10)

        send_button = tk.Button(
            fifth_row_frame, text="Send Signal")
        send_button.pack()
