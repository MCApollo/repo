#include <Python.h>
#include "pyobjc-api.h"
#import <UIKit/UIKit.h>

#define _trace() \
    fprintf(stderr, "_trace():%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__)

#define _assert(test) \
    do if (!(test)) { \
        fprintf(stderr, "_assert(%s):%s(%d):%s\n", #test, __FILE__, __LINE__, __FUNCTION__); \
        exit(-1); \
    } while (false)

static PyObject*  objc_UIApplicationMain(
    PyObject *self __attribute__((__unused__)),
    PyObject *args
) {
    int argc;
    char **argv;
    size_t i;
    int res = -1;

    PyObject *arga;
    PyObject *_class = NULL;

#ifdef __OBJC2__
    PyObject *principal;
    PyObject *delegate;
#endif

    _assert(PyObjC_API != NULL);
    _assert(args != NULL);

    if (PyArg_ParseTuple(args, "OO", &arga, &_class)) {
        if (_class == NULL) {
            PyErr_SetString(PyExc_TypeError, "UIApplicationMain: null class");
            return NULL;
        }
    }
#ifdef __OBJC2__
    else if (!PyArg_ParseTuple(args, "OOO", &arga, &principal, &delegate)) {
    }
#endif
    else {
        PyErr_SetString(PyExc_TypeError, "Invalid Arguments");
        return NULL;
    }

    _assert(arga != NULL);

    argc = PySequence_Size(arga);
    argv = calloc(argc + 1, sizeof(char *));

    if (argv == NULL) {
	PyErr_SetString(PyExc_MemoryError, "Out of memory");
	return NULL;
    }

    for (i = 0; i != argc; ++i) {
        PyObject *arg = PySequence_GetItem(arga, i);
        if (arg == NULL) {
            PyErr_SetString(PyExc_TypeError, "UIApplicationMain: null argument");
            goto error;
        }

        if (!PyString_Check(arg)) {
            PyErr_SetString(PyExc_TypeError, "UIApplicationMain: non-string argument");
            goto error;
        }

        argv[i] = strdup(PyString_AsString(arg));
        if (argv[i] == NULL) {
            PyErr_SetString(PyExc_MemoryError, "Out of memory");
            goto error;
        }
    }

    PyObjC_DURING
#ifdef __OBJC2__
        if (_class == NULL)
            res = UIApplicationMain(argc, argv,
                /* XXX: do I have to do these null checks? */
                principal == NULL ? nil : PyObjCObject_GetObject(principal),
                delegate == NULL ? nil : PyObjCObject_GetObject(delegate)
            );
        else {
            NSString *name = [NSString stringWithUTF8String:class_getName(PyObjCClass_GetClass(_class))];
            res = UIApplicationMain(argc, argv, name, name);
        }
#else
        res = UIApplicationMain(argc, argv, PyObjCClass_GetClass(_class));
#endif
    PyObjC_HANDLER
        PyObjCErr_FromObjC(localException);
    PyObjC_ENDHANDLER

  error:
    for (i = 0; i != argc; ++i)
        free(argv[i]);
    free(argv);

    if (res == -1 && PyErr_Occurred())
        return NULL;
    return PyInt_FromLong(res);
}

static PyMethodDef mod_methods[] = {{
    "UIApplicationMain",
    /*(PyCFunction)*/ objc_UIApplicationMain,
    METH_VARARGS|METH_KEYWORDS,
#ifdef __OBJC2__
    "int UIApplicationMain(int argc, char *argv[], NSString *principalClassName, NSString *delegateClassName);"
#else
    "int UIApplicationMain(int argc, char *argv[], Class _class);"
#endif
}, {
    NULL, NULL, 0, NULL
}};

void init_uicaboodle(void) {
    PyObject *module = Py_InitModule4("_uicaboodle", mod_methods, "", NULL, PYTHON_API_VERSION);
    PyObjC_ImportAPI(module);
}
