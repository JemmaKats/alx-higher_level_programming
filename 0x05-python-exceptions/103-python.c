#include <Python.h>

void print_python_list(PyObject *p)
{
    long int size, i;
    PyListObject *list;
    PyObject *item;

    printf("[*] Python list info\n");
    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    list = (PyListObject *)p;
    size = Py_SIZE(p);

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", list->allocated);
    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, item->ob_type->tp_name);
        if (PyBytes_Check(item))
            print_python_bytes(item);
    }
}

void print_python_bytes(PyObject *p)
{
    unsigned char *str;
    Py_ssize_t size, i;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    str = ((PyBytesObject *)p)->ob_sval;

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);
    
    if (size < 10)
        printf("  first %ld bytes:", size + 1);
    else
        printf("  first 10 bytes:");

    for (i = 0; i <= size && i < 10; i++)
        printf(" %02hhx", str[i]);
    
    printf("\n");
}

void print_python_float(PyObject *p)
{
    double value;

    printf("[.] float object info\n");
    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    value = ((PyFloatObject *)p)->ob_fval;
    
    printf("  value: %lf\n", value);
}
