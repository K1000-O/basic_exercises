from typing import Tuple


class Node:
    """_summary_

    Returns:
        _type_: _description_
    """
    id = 0

    def __init__(self, name) -> None:
        self.__id = self.id
        self.__name = name

        type(self).id += 1 # We increase on 1 the nº of nodes (id).

    def __str__(self) -> Tuple:
        return f"{self.__name}({self.__id})."

    def getId(self) -> int:
        return self.__id

    def getName(self) -> str:
        return self.__name
