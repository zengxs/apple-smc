#include "smc.h"

static PyObject *py_open_smc(PyObject *self, PyObject *args) {
  return Py_BuildValue("i", open_smc());
}

static PyObject *py_close_smc(PyObject *self, PyObject *args) {
  return Py_BuildValue("i", close_smc());
}

static PyObject *py_get_temperature(PyObject *self, PyObject *args) {
  char *key;
  if (!PyArg_ParseTuple(args, "s", &key)) {
    return NULL;
  }
  return Py_BuildValue("d", get_temperature(key));
}

static PyMethodDef smc_methods[] = {
    {"open_smc", py_open_smc, METH_NOARGS, ""},
    {"close_smc", py_close_smc, METH_NOARGS, ""},
    {"get_temperature", py_get_temperature, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL},
};

static PyModuleDef smc_module = {
    PyModuleDef_HEAD_INIT,
    "_smc",                       // name of module,
    "Apple SMC low level module", // doc string
    -1,
    smc_methods // method table
};

PyMODINIT_FUNC PyInit__smc(void) { return PyModule_Create(&smc_module); }
