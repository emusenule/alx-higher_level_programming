#include <Python.h>
#include <stdio.h>

void print_python_object(PyObject *p)
{
	if (PyList_Check(p))
	{
		Py_ssize_t size = PyList_Size(p);
		Py_ssize_t i;

		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %zd\n", size);
		printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

		for (i = 0; i < size; i++)
		{
			printf("Element %zd: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
		}
	} else if (PyBytes_Check(p))
	{
		Py_ssize_t size;
		char *bytes_str;
		int i;

		printf("[.] bytes object info\n");

		if (!PyBytes_Check(p))
		{
			printf("  [ERROR] Invalid Bytes object\n");
			return;
		}

		size = PyBytes_Size(p);
		bytes_str = PyBytes_AsString(p);

		printf("  size: %zd\n", size);
		printf("  trying string: %s\n", bytes_str);

		printf("  first %zd bytes: ", (size < 10) ? size + 1 : 10);
		for (i = 0; i < 10 && i <= size; i++)
		{
			printf("%02x", (unsigned char)bytes_str[i]);
			if (i == 9 || i == size)
				break;
			printf(" ");
		}
		printf("\n");
	} else 
	{
		printf("[ERROR] Unknown object type\n");
	}
}
