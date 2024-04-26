import tkinter as tk
from typing import Dict

import ttkbootstrap as tb
from call_c_functions import call_list_process, call_send_signal
from ttkbootstrap.dialogs import Messagebox

PROCESS_TYPE = {'User': 0, 'All': 1}

class ProcessManager():

    def __init__(self, root):
        self.root = root
        self.root.title('Process Manager')
        self.root.geometry('1300x700')

        self.pro_type_menu = tb.Menubutton(self.root,
                                           text="Type",
                                           bootstyle="info")
        self.pro_type_insied_menu = tb.Menu(self.pro_type_menu)

        self.pro_type_var = tk.StringVar()
        for index, x in enumerate(['User', 'All']):
            self.pro_type_insied_menu.add_radiobutton(label=x,
                                                      variable=self.pro_type_var,
                                                      font=('Arial', 14),
                                                      command=lambda i=index: self.update_process_type(i))
        self.pro_type_menu['menu'] = self.pro_type_insied_menu

        self.pro_type_label = tb.Label(
            self.root, text="Process Type",
            bootstyle="info", font=('Arial', 18))

        self.pro_type_label.grid(row=0, column=0, padx=10, pady=10)
        self.pro_type_menu.grid(row=0, column=1, padx=10, pady=10)

    def update_process_type(self, type: int) -> None:
        self.pro_type_menu.config(text=self.pro_type_var.get())
        process_list = call_list_process(type)
        if 'Error' in process_list.keys():
            Messagebox.showerror('Error', process_list['Error'])
            return
        self.do_treeview(process_list)
        print(process_list)
        print(self.pro_type_var.get())

    def do_treeview(self, process_list: Dict[str, str]) -> None:
        columns = ['USER', 'PID', '%CPU', '%MEM', 'TIME', 'COMMAND']
        self.tree = tb.Treeview(self.root,
                                bootstyle="success",
                                columns=columns,
                                show="headings"
                                )
        for col in columns:
            self.tree.heading(col, text=col)

        for index, process in enumerate(process_list['process']):
            self.tree.insert('', index, values=process)

        self.tree.grid(row=1, column=0, columnspan=2, padx=10, pady=10)
        h_scroll = tb.Scrollbar(self.root, orient='horizontal')
        v_scroll = tb.Scrollbar(self.root, orient='vertical')
        self.configure_tree_scrollbars(self.tree, h_scroll, v_scroll)
        h_scroll.grid(row=2, column=0, columnspan=2, sticky='ew')
        v_scroll.grid(row=1, column=2, sticky='ns')

        self.tree.after(1000, lambda: self.update_process_type(PROCESS_TYPE[self.pro_type_var.get()]))


    @staticmethod
    def configure_tree_scrollbars(tree, h_scroll, v_scroll):
        tree.configure(xscrollcommand=h_scroll.set,
                       yscrollcommand=v_scroll.set)
        h_scroll.config(command=tree.xview)
        v_scroll.config(command=tree.yview)
