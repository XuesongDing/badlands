/* File: wavesedsmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Wed Aug 14 11:59:45 2019
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *waveseds_error;
static PyObject *waveseds_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(waveseds_error,errstring);\
        /*goto capi_fail;*/\
    } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyFloat_Check(obj)) {
#ifdef __sgi
        *v = PyFloat_AsDouble(obj);
#else
        *v = PyFloat_AS_DOUBLE(obj);
#endif
        return 1;
    }
    tmp = PyNumber_Float(obj);
    if (tmp) {
#ifdef __sgi
        *v = PyFloat_AsDouble(tmp);
#else
        *v = PyFloat_AS_DOUBLE(tmp);
#endif
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = waveseds_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyInt_Check(obj)) {
        *v = (int)PyInt_AS_LONG(obj);
        return 1;
    }
    tmp = PyNumber_Int(obj);
    if (tmp) {
        *v = PyInt_AS_LONG(tmp);
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = waveseds_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(airymodel,AIRYMODEL)(double*,double*,double*,double*,double*,int*,int*,double*,double*,double*,double*,int*,int*);
extern void F_FUNC(wavtransport,WAVTRANSPORT)(int*,double*,double*,double*,double*,double*,double*,int*,int*);
extern void F_FUNC(wavdiffusion,WAVDIFFUSION)(double*,double*,double*,double*,double*,int*,double*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************* airymodel *********************************/
static char doc_f2py_rout_waveseds_airymodel[] = "\
pc,pl,ptravel,pwaveh = airymodel(pdx,pdd,ph0,pdepth,psrc,pinland,pshadow,[pnumrow,pnumcol])\n\nWrapper for ``airymodel``.\
\n\nParameters\n----------\n"
"pdx : input float\n"
"pdd : input float\n"
"ph0 : input float\n"
"pdepth : input rank-2 array('d') with bounds (pnumrow,pnumcol)\n"
"psrc : input rank-2 array('d') with bounds (pnumrow,pnumcol)\n"
"pinland : input rank-2 array('i') with bounds (pnumrow,pnumcol)\n"
"pshadow : input int\n"
"\nOther Parameters\n----------------\n"
"pnumrow : input int, optional\n    Default: shape(pdepth,0)\n"
"pnumcol : input int, optional\n    Default: shape(pdepth,1)\n"
"\nReturns\n-------\n"
"pc : rank-2 array('d') with bounds (pnumrow,pnumcol)\n"
"pl : rank-2 array('d') with bounds (pnumrow,pnumcol)\n"
"ptravel : rank-2 array('d') with bounds (pnumrow,pnumcol)\n"
"pwaveh : rank-2 array('d') with bounds (pnumrow,pnumcol)";
/* extern void F_FUNC(airymodel,AIRYMODEL)(double*,double*,double*,double*,double*,int*,int*,double*,double*,double*,double*,int*,int*); */
static PyObject *f2py_rout_waveseds_airymodel(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,double*,double*,int*,int*,double*,double*,double*,double*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double pdx = 0;
  PyObject *pdx_capi = Py_None;
  double pdd = 0;
  PyObject *pdd_capi = Py_None;
  double ph0 = 0;
  PyObject *ph0_capi = Py_None;
  double *pdepth = NULL;
  npy_intp pdepth_Dims[2] = {-1, -1};
  const int pdepth_Rank = 2;
  PyArrayObject *capi_pdepth_tmp = NULL;
  int capi_pdepth_intent = 0;
  PyObject *pdepth_capi = Py_None;
  double *psrc = NULL;
  npy_intp psrc_Dims[2] = {-1, -1};
  const int psrc_Rank = 2;
  PyArrayObject *capi_psrc_tmp = NULL;
  int capi_psrc_intent = 0;
  PyObject *psrc_capi = Py_None;
  int *pinland = NULL;
  npy_intp pinland_Dims[2] = {-1, -1};
  const int pinland_Rank = 2;
  PyArrayObject *capi_pinland_tmp = NULL;
  int capi_pinland_intent = 0;
  PyObject *pinland_capi = Py_None;
  int pshadow = 0;
  PyObject *pshadow_capi = Py_None;
  double *pc = NULL;
  npy_intp pc_Dims[2] = {-1, -1};
  const int pc_Rank = 2;
  PyArrayObject *capi_pc_tmp = NULL;
  int capi_pc_intent = 0;
  double *pl = NULL;
  npy_intp pl_Dims[2] = {-1, -1};
  const int pl_Rank = 2;
  PyArrayObject *capi_pl_tmp = NULL;
  int capi_pl_intent = 0;
  double *ptravel = NULL;
  npy_intp ptravel_Dims[2] = {-1, -1};
  const int ptravel_Rank = 2;
  PyArrayObject *capi_ptravel_tmp = NULL;
  int capi_ptravel_intent = 0;
  double *pwaveh = NULL;
  npy_intp pwaveh_Dims[2] = {-1, -1};
  const int pwaveh_Rank = 2;
  PyArrayObject *capi_pwaveh_tmp = NULL;
  int capi_pwaveh_intent = 0;
  int pnumrow = 0;
  PyObject *pnumrow_capi = Py_None;
  int pnumcol = 0;
  PyObject *pnumcol_capi = Py_None;
  static char *capi_kwlist[] = {"pdx","pdd","ph0","pdepth","psrc","pinland","pshadow","pnumrow","pnumcol",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOOO|OO:waveseds.airymodel",\
    capi_kwlist,&pdx_capi,&pdd_capi,&ph0_capi,&pdepth_capi,&psrc_capi,&pinland_capi,&pshadow_capi,&pnumrow_capi,&pnumcol_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable pdd */
    f2py_success = double_from_pyobj(&pdd,pdd_capi,"waveseds.airymodel() 2nd argument (pdd) can't be converted to double");
  if (f2py_success) {
  /* Processing variable pdepth */
  ;
  capi_pdepth_intent |= F2PY_INTENT_IN;
  capi_pdepth_tmp = array_from_pyobj(NPY_DOUBLE,pdepth_Dims,pdepth_Rank,capi_pdepth_intent,pdepth_capi);
  if (capi_pdepth_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 4th argument `pdepth' of waveseds.airymodel to C/Fortran array" );
  } else {
    pdepth = (double *)(PyArray_DATA(capi_pdepth_tmp));

  /* Processing variable pdx */
    f2py_success = double_from_pyobj(&pdx,pdx_capi,"waveseds.airymodel() 1st argument (pdx) can't be converted to double");
  if (f2py_success) {
  /* Processing variable pshadow */
    f2py_success = int_from_pyobj(&pshadow,pshadow_capi,"waveseds.airymodel() 7th argument (pshadow) can't be converted to int");
  if (f2py_success) {
  /* Processing variable ph0 */
    f2py_success = double_from_pyobj(&ph0,ph0_capi,"waveseds.airymodel() 3rd argument (ph0) can't be converted to double");
  if (f2py_success) {
  /* Processing variable pnumcol */
  if (pnumcol_capi == Py_None) pnumcol = shape(pdepth,1); else
    f2py_success = int_from_pyobj(&pnumcol,pnumcol_capi,"waveseds.airymodel() 2nd keyword (pnumcol) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(pdepth,1)==pnumcol,"shape(pdepth,1)==pnumcol","2nd keyword pnumcol","airymodel:pnumcol=%d",pnumcol) {
  /* Processing variable pnumrow */
  if (pnumrow_capi == Py_None) pnumrow = shape(pdepth,0); else
    f2py_success = int_from_pyobj(&pnumrow,pnumrow_capi,"waveseds.airymodel() 1st keyword (pnumrow) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(pdepth,0)==pnumrow,"shape(pdepth,0)==pnumrow","1st keyword pnumrow","airymodel:pnumrow=%d",pnumrow) {
  /* Processing variable pwaveh */
  pwaveh_Dims[0]=pnumrow,pwaveh_Dims[1]=pnumcol;
  capi_pwaveh_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_pwaveh_tmp = array_from_pyobj(NPY_DOUBLE,pwaveh_Dims,pwaveh_Rank,capi_pwaveh_intent,Py_None);
  if (capi_pwaveh_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting hidden `pwaveh' of waveseds.airymodel to C/Fortran array" );
  } else {
    pwaveh = (double *)(PyArray_DATA(capi_pwaveh_tmp));

  /* Processing variable pl */
  pl_Dims[0]=pnumrow,pl_Dims[1]=pnumcol;
  capi_pl_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_pl_tmp = array_from_pyobj(NPY_DOUBLE,pl_Dims,pl_Rank,capi_pl_intent,Py_None);
  if (capi_pl_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting hidden `pl' of waveseds.airymodel to C/Fortran array" );
  } else {
    pl = (double *)(PyArray_DATA(capi_pl_tmp));

  /* Processing variable ptravel */
  ptravel_Dims[0]=pnumrow,ptravel_Dims[1]=pnumcol;
  capi_ptravel_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_ptravel_tmp = array_from_pyobj(NPY_DOUBLE,ptravel_Dims,ptravel_Rank,capi_ptravel_intent,Py_None);
  if (capi_ptravel_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting hidden `ptravel' of waveseds.airymodel to C/Fortran array" );
  } else {
    ptravel = (double *)(PyArray_DATA(capi_ptravel_tmp));

  /* Processing variable psrc */
  psrc_Dims[0]=pnumrow,psrc_Dims[1]=pnumcol;
  capi_psrc_intent |= F2PY_INTENT_IN;
  capi_psrc_tmp = array_from_pyobj(NPY_DOUBLE,psrc_Dims,psrc_Rank,capi_psrc_intent,psrc_capi);
  if (capi_psrc_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 5th argument `psrc' of waveseds.airymodel to C/Fortran array" );
  } else {
    psrc = (double *)(PyArray_DATA(capi_psrc_tmp));

  /* Processing variable pinland */
  pinland_Dims[0]=pnumrow,pinland_Dims[1]=pnumcol;
  capi_pinland_intent |= F2PY_INTENT_IN;
  capi_pinland_tmp = array_from_pyobj(NPY_INT,pinland_Dims,pinland_Rank,capi_pinland_intent,pinland_capi);
  if (capi_pinland_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 6th argument `pinland' of waveseds.airymodel to C/Fortran array" );
  } else {
    pinland = (int *)(PyArray_DATA(capi_pinland_tmp));

  /* Processing variable pc */
  pc_Dims[0]=pnumrow,pc_Dims[1]=pnumcol;
  capi_pc_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_pc_tmp = array_from_pyobj(NPY_DOUBLE,pc_Dims,pc_Rank,capi_pc_intent,Py_None);
  if (capi_pc_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting hidden `pc' of waveseds.airymodel to C/Fortran array" );
  } else {
    pc = (double *)(PyArray_DATA(capi_pc_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&pdx,&pdd,&ph0,pdepth,psrc,pinland,&pshadow,pc,pl,ptravel,pwaveh,&pnumrow,&pnumcol);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("NNNN",capi_pc_tmp,capi_pl_tmp,capi_ptravel_tmp,capi_pwaveh_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_pc_tmp == NULL) ... else of pc*/
  /* End of cleaning variable pc */
  if((PyObject *)capi_pinland_tmp!=pinland_capi) {
    Py_XDECREF(capi_pinland_tmp); }
  }  /*if (capi_pinland_tmp == NULL) ... else of pinland*/
  /* End of cleaning variable pinland */
  if((PyObject *)capi_psrc_tmp!=psrc_capi) {
    Py_XDECREF(capi_psrc_tmp); }
  }  /*if (capi_psrc_tmp == NULL) ... else of psrc*/
  /* End of cleaning variable psrc */
  }  /*if (capi_ptravel_tmp == NULL) ... else of ptravel*/
  /* End of cleaning variable ptravel */
  }  /*if (capi_pl_tmp == NULL) ... else of pl*/
  /* End of cleaning variable pl */
  }  /*if (capi_pwaveh_tmp == NULL) ... else of pwaveh*/
  /* End of cleaning variable pwaveh */
  } /*CHECKSCALAR(shape(pdepth,0)==pnumrow)*/
  } /*if (f2py_success) of pnumrow*/
  /* End of cleaning variable pnumrow */
  } /*CHECKSCALAR(shape(pdepth,1)==pnumcol)*/
  } /*if (f2py_success) of pnumcol*/
  /* End of cleaning variable pnumcol */
  } /*if (f2py_success) of ph0*/
  /* End of cleaning variable ph0 */
  } /*if (f2py_success) of pshadow*/
  /* End of cleaning variable pshadow */
  } /*if (f2py_success) of pdx*/
  /* End of cleaning variable pdx */
  if((PyObject *)capi_pdepth_tmp!=pdepth_capi) {
    Py_XDECREF(capi_pdepth_tmp); }
  }  /*if (capi_pdepth_tmp == NULL) ... else of pdepth*/
  /* End of cleaning variable pdepth */
  } /*if (f2py_success) of pdd*/
  /* End of cleaning variable pdd */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/****************************** end of airymodel ******************************/

/******************************** wavtransport ********************************/
static char doc_f2py_rout_waveseds_wavtransport[] = "\
pydz,pydist = wavtransport(pyits,pydepth,pyhent,pytransx,pytransy,[pynrow,pyncol])\n\nWrapper for ``wavtransport``.\
\n\nParameters\n----------\n"
"pyits : input int\n"
"pydepth : input rank-2 array('d') with bounds (pynrow,pyncol)\n"
"pyhent : input rank-2 array('d') with bounds (pynrow,pyncol)\n"
"pytransx : input rank-2 array('d') with bounds (pynrow,pyncol)\n"
"pytransy : input rank-2 array('d') with bounds (pynrow,pyncol)\n"
"\nOther Parameters\n----------------\n"
"pynrow : input int, optional\n    Default: shape(pydepth,0)\n"
"pyncol : input int, optional\n    Default: shape(pydepth,1)\n"
"\nReturns\n-------\n"
"pydz : rank-2 array('d') with bounds (pynrow,pyncol)\n"
"pydist : rank-2 array('d') with bounds (pynrow,pyncol)";
/* extern void F_FUNC(wavtransport,WAVTRANSPORT)(int*,double*,double*,double*,double*,double*,double*,int*,int*); */
static PyObject *f2py_rout_waveseds_wavtransport(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,double*,double*,double*,double*,double*,double*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int pyits = 0;
  PyObject *pyits_capi = Py_None;
  double *pydepth = NULL;
  npy_intp pydepth_Dims[2] = {-1, -1};
  const int pydepth_Rank = 2;
  PyArrayObject *capi_pydepth_tmp = NULL;
  int capi_pydepth_intent = 0;
  PyObject *pydepth_capi = Py_None;
  double *pyhent = NULL;
  npy_intp pyhent_Dims[2] = {-1, -1};
  const int pyhent_Rank = 2;
  PyArrayObject *capi_pyhent_tmp = NULL;
  int capi_pyhent_intent = 0;
  PyObject *pyhent_capi = Py_None;
  double *pytransx = NULL;
  npy_intp pytransx_Dims[2] = {-1, -1};
  const int pytransx_Rank = 2;
  PyArrayObject *capi_pytransx_tmp = NULL;
  int capi_pytransx_intent = 0;
  PyObject *pytransx_capi = Py_None;
  double *pytransy = NULL;
  npy_intp pytransy_Dims[2] = {-1, -1};
  const int pytransy_Rank = 2;
  PyArrayObject *capi_pytransy_tmp = NULL;
  int capi_pytransy_intent = 0;
  PyObject *pytransy_capi = Py_None;
  double *pydz = NULL;
  npy_intp pydz_Dims[2] = {-1, -1};
  const int pydz_Rank = 2;
  PyArrayObject *capi_pydz_tmp = NULL;
  int capi_pydz_intent = 0;
  double *pydist = NULL;
  npy_intp pydist_Dims[2] = {-1, -1};
  const int pydist_Rank = 2;
  PyArrayObject *capi_pydist_tmp = NULL;
  int capi_pydist_intent = 0;
  int pynrow = 0;
  PyObject *pynrow_capi = Py_None;
  int pyncol = 0;
  PyObject *pyncol_capi = Py_None;
  static char *capi_kwlist[] = {"pyits","pydepth","pyhent","pytransx","pytransy","pynrow","pyncol",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOO|OO:waveseds.wavtransport",\
    capi_kwlist,&pyits_capi,&pydepth_capi,&pyhent_capi,&pytransx_capi,&pytransy_capi,&pynrow_capi,&pyncol_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable pyits */
    f2py_success = int_from_pyobj(&pyits,pyits_capi,"waveseds.wavtransport() 1st argument (pyits) can't be converted to int");
  if (f2py_success) {
  /* Processing variable pydepth */
  ;
  capi_pydepth_intent |= F2PY_INTENT_IN;
  capi_pydepth_tmp = array_from_pyobj(NPY_DOUBLE,pydepth_Dims,pydepth_Rank,capi_pydepth_intent,pydepth_capi);
  if (capi_pydepth_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 2nd argument `pydepth' of waveseds.wavtransport to C/Fortran array" );
  } else {
    pydepth = (double *)(PyArray_DATA(capi_pydepth_tmp));

  /* Processing variable pyncol */
  if (pyncol_capi == Py_None) pyncol = shape(pydepth,1); else
    f2py_success = int_from_pyobj(&pyncol,pyncol_capi,"waveseds.wavtransport() 2nd keyword (pyncol) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(pydepth,1)==pyncol,"shape(pydepth,1)==pyncol","2nd keyword pyncol","wavtransport:pyncol=%d",pyncol) {
  /* Processing variable pynrow */
  if (pynrow_capi == Py_None) pynrow = shape(pydepth,0); else
    f2py_success = int_from_pyobj(&pynrow,pynrow_capi,"waveseds.wavtransport() 1st keyword (pynrow) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(pydepth,0)==pynrow,"shape(pydepth,0)==pynrow","1st keyword pynrow","wavtransport:pynrow=%d",pynrow) {
  /* Processing variable pydz */
  pydz_Dims[0]=pynrow,pydz_Dims[1]=pyncol;
  capi_pydz_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_pydz_tmp = array_from_pyobj(NPY_DOUBLE,pydz_Dims,pydz_Rank,capi_pydz_intent,Py_None);
  if (capi_pydz_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting hidden `pydz' of waveseds.wavtransport to C/Fortran array" );
  } else {
    pydz = (double *)(PyArray_DATA(capi_pydz_tmp));

  /* Processing variable pydist */
  pydist_Dims[0]=pynrow,pydist_Dims[1]=pyncol;
  capi_pydist_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_pydist_tmp = array_from_pyobj(NPY_DOUBLE,pydist_Dims,pydist_Rank,capi_pydist_intent,Py_None);
  if (capi_pydist_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting hidden `pydist' of waveseds.wavtransport to C/Fortran array" );
  } else {
    pydist = (double *)(PyArray_DATA(capi_pydist_tmp));

  /* Processing variable pyhent */
  pyhent_Dims[0]=pynrow,pyhent_Dims[1]=pyncol;
  capi_pyhent_intent |= F2PY_INTENT_IN;
  capi_pyhent_tmp = array_from_pyobj(NPY_DOUBLE,pyhent_Dims,pyhent_Rank,capi_pyhent_intent,pyhent_capi);
  if (capi_pyhent_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 3rd argument `pyhent' of waveseds.wavtransport to C/Fortran array" );
  } else {
    pyhent = (double *)(PyArray_DATA(capi_pyhent_tmp));

  /* Processing variable pytransy */
  pytransy_Dims[0]=pynrow,pytransy_Dims[1]=pyncol;
  capi_pytransy_intent |= F2PY_INTENT_IN;
  capi_pytransy_tmp = array_from_pyobj(NPY_DOUBLE,pytransy_Dims,pytransy_Rank,capi_pytransy_intent,pytransy_capi);
  if (capi_pytransy_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 5th argument `pytransy' of waveseds.wavtransport to C/Fortran array" );
  } else {
    pytransy = (double *)(PyArray_DATA(capi_pytransy_tmp));

  /* Processing variable pytransx */
  pytransx_Dims[0]=pynrow,pytransx_Dims[1]=pyncol;
  capi_pytransx_intent |= F2PY_INTENT_IN;
  capi_pytransx_tmp = array_from_pyobj(NPY_DOUBLE,pytransx_Dims,pytransx_Rank,capi_pytransx_intent,pytransx_capi);
  if (capi_pytransx_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 4th argument `pytransx' of waveseds.wavtransport to C/Fortran array" );
  } else {
    pytransx = (double *)(PyArray_DATA(capi_pytransx_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&pyits,pydepth,pyhent,pytransx,pytransy,pydz,pydist,&pynrow,&pyncol);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("NN",capi_pydz_tmp,capi_pydist_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_pytransx_tmp!=pytransx_capi) {
    Py_XDECREF(capi_pytransx_tmp); }
  }  /*if (capi_pytransx_tmp == NULL) ... else of pytransx*/
  /* End of cleaning variable pytransx */
  if((PyObject *)capi_pytransy_tmp!=pytransy_capi) {
    Py_XDECREF(capi_pytransy_tmp); }
  }  /*if (capi_pytransy_tmp == NULL) ... else of pytransy*/
  /* End of cleaning variable pytransy */
  if((PyObject *)capi_pyhent_tmp!=pyhent_capi) {
    Py_XDECREF(capi_pyhent_tmp); }
  }  /*if (capi_pyhent_tmp == NULL) ... else of pyhent*/
  /* End of cleaning variable pyhent */
  }  /*if (capi_pydist_tmp == NULL) ... else of pydist*/
  /* End of cleaning variable pydist */
  }  /*if (capi_pydz_tmp == NULL) ... else of pydz*/
  /* End of cleaning variable pydz */
  } /*CHECKSCALAR(shape(pydepth,0)==pynrow)*/
  } /*if (f2py_success) of pynrow*/
  /* End of cleaning variable pynrow */
  } /*CHECKSCALAR(shape(pydepth,1)==pyncol)*/
  } /*if (f2py_success) of pyncol*/
  /* End of cleaning variable pyncol */
  if((PyObject *)capi_pydepth_tmp!=pydepth_capi) {
    Py_XDECREF(capi_pydepth_tmp); }
  }  /*if (capi_pydepth_tmp == NULL) ... else of pydepth*/
  /* End of cleaning variable pydepth */
  } /*if (f2py_success) of pyits*/
  /* End of cleaning variable pyits */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/**************************** end of wavtransport ****************************/

/******************************** wavdiffusion ********************************/
static char doc_f2py_rout_waveseds_wavdiffusion[] = "\
depopy = wavdiffusion(oelevpy,dzpy,coeffpy,maxthpy,tsteppy,nsteppy,[numrowpy,numcolpy])\n\nWrapper for ``wavdiffusion``.\
\n\nParameters\n----------\n"
"oelevpy : input rank-2 array('d') with bounds (numrowpy,numcolpy)\n"
"dzpy : input rank-2 array('d') with bounds (numrowpy,numcolpy)\n"
"coeffpy : input float\n"
"maxthpy : input float\n"
"tsteppy : input float\n"
"nsteppy : input int\n"
"\nOther Parameters\n----------------\n"
"numrowpy : input int, optional\n    Default: shape(oelevpy,0)\n"
"numcolpy : input int, optional\n    Default: shape(oelevpy,1)\n"
"\nReturns\n-------\n"
"depopy : rank-2 array('d') with bounds (numrowpy,numcolpy)";
/* extern void F_FUNC(wavdiffusion,WAVDIFFUSION)(double*,double*,double*,double*,double*,int*,double*,int*,int*); */
static PyObject *f2py_rout_waveseds_wavdiffusion(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,double*,double*,int*,double*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *oelevpy = NULL;
  npy_intp oelevpy_Dims[2] = {-1, -1};
  const int oelevpy_Rank = 2;
  PyArrayObject *capi_oelevpy_tmp = NULL;
  int capi_oelevpy_intent = 0;
  PyObject *oelevpy_capi = Py_None;
  double *dzpy = NULL;
  npy_intp dzpy_Dims[2] = {-1, -1};
  const int dzpy_Rank = 2;
  PyArrayObject *capi_dzpy_tmp = NULL;
  int capi_dzpy_intent = 0;
  PyObject *dzpy_capi = Py_None;
  double coeffpy = 0;
  PyObject *coeffpy_capi = Py_None;
  double maxthpy = 0;
  PyObject *maxthpy_capi = Py_None;
  double tsteppy = 0;
  PyObject *tsteppy_capi = Py_None;
  int nsteppy = 0;
  PyObject *nsteppy_capi = Py_None;
  double *depopy = NULL;
  npy_intp depopy_Dims[2] = {-1, -1};
  const int depopy_Rank = 2;
  PyArrayObject *capi_depopy_tmp = NULL;
  int capi_depopy_intent = 0;
  int numrowpy = 0;
  PyObject *numrowpy_capi = Py_None;
  int numcolpy = 0;
  PyObject *numcolpy_capi = Py_None;
  static char *capi_kwlist[] = {"oelevpy","dzpy","coeffpy","maxthpy","tsteppy","nsteppy","numrowpy","numcolpy",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOO|OO:waveseds.wavdiffusion",\
    capi_kwlist,&oelevpy_capi,&dzpy_capi,&coeffpy_capi,&maxthpy_capi,&tsteppy_capi,&nsteppy_capi,&numrowpy_capi,&numcolpy_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable tsteppy */
    f2py_success = double_from_pyobj(&tsteppy,tsteppy_capi,"waveseds.wavdiffusion() 5th argument (tsteppy) can't be converted to double");
  if (f2py_success) {
  /* Processing variable nsteppy */
    f2py_success = int_from_pyobj(&nsteppy,nsteppy_capi,"waveseds.wavdiffusion() 6th argument (nsteppy) can't be converted to int");
  if (f2py_success) {
  /* Processing variable coeffpy */
    f2py_success = double_from_pyobj(&coeffpy,coeffpy_capi,"waveseds.wavdiffusion() 3rd argument (coeffpy) can't be converted to double");
  if (f2py_success) {
  /* Processing variable maxthpy */
    f2py_success = double_from_pyobj(&maxthpy,maxthpy_capi,"waveseds.wavdiffusion() 4th argument (maxthpy) can't be converted to double");
  if (f2py_success) {
  /* Processing variable oelevpy */
  ;
  capi_oelevpy_intent |= F2PY_INTENT_IN;
  capi_oelevpy_tmp = array_from_pyobj(NPY_DOUBLE,oelevpy_Dims,oelevpy_Rank,capi_oelevpy_intent,oelevpy_capi);
  if (capi_oelevpy_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 1st argument `oelevpy' of waveseds.wavdiffusion to C/Fortran array" );
  } else {
    oelevpy = (double *)(PyArray_DATA(capi_oelevpy_tmp));

  /* Processing variable numrowpy */
  if (numrowpy_capi == Py_None) numrowpy = shape(oelevpy,0); else
    f2py_success = int_from_pyobj(&numrowpy,numrowpy_capi,"waveseds.wavdiffusion() 1st keyword (numrowpy) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(oelevpy,0)==numrowpy,"shape(oelevpy,0)==numrowpy","1st keyword numrowpy","wavdiffusion:numrowpy=%d",numrowpy) {
  /* Processing variable numcolpy */
  if (numcolpy_capi == Py_None) numcolpy = shape(oelevpy,1); else
    f2py_success = int_from_pyobj(&numcolpy,numcolpy_capi,"waveseds.wavdiffusion() 2nd keyword (numcolpy) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(oelevpy,1)==numcolpy,"shape(oelevpy,1)==numcolpy","2nd keyword numcolpy","wavdiffusion:numcolpy=%d",numcolpy) {
  /* Processing variable dzpy */
  dzpy_Dims[0]=numrowpy,dzpy_Dims[1]=numcolpy;
  capi_dzpy_intent |= F2PY_INTENT_IN;
  capi_dzpy_tmp = array_from_pyobj(NPY_DOUBLE,dzpy_Dims,dzpy_Rank,capi_dzpy_intent,dzpy_capi);
  if (capi_dzpy_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting 2nd argument `dzpy' of waveseds.wavdiffusion to C/Fortran array" );
  } else {
    dzpy = (double *)(PyArray_DATA(capi_dzpy_tmp));

  /* Processing variable depopy */
  depopy_Dims[0]=numrowpy,depopy_Dims[1]=numcolpy;
  capi_depopy_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_depopy_tmp = array_from_pyobj(NPY_DOUBLE,depopy_Dims,depopy_Rank,capi_depopy_intent,Py_None);
  if (capi_depopy_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(waveseds_error,"failed in converting hidden `depopy' of waveseds.wavdiffusion to C/Fortran array" );
  } else {
    depopy = (double *)(PyArray_DATA(capi_depopy_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(oelevpy,dzpy,&coeffpy,&maxthpy,&tsteppy,&nsteppy,depopy,&numrowpy,&numcolpy);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_depopy_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_depopy_tmp == NULL) ... else of depopy*/
  /* End of cleaning variable depopy */
  if((PyObject *)capi_dzpy_tmp!=dzpy_capi) {
    Py_XDECREF(capi_dzpy_tmp); }
  }  /*if (capi_dzpy_tmp == NULL) ... else of dzpy*/
  /* End of cleaning variable dzpy */
  } /*CHECKSCALAR(shape(oelevpy,1)==numcolpy)*/
  } /*if (f2py_success) of numcolpy*/
  /* End of cleaning variable numcolpy */
  } /*CHECKSCALAR(shape(oelevpy,0)==numrowpy)*/
  } /*if (f2py_success) of numrowpy*/
  /* End of cleaning variable numrowpy */
  if((PyObject *)capi_oelevpy_tmp!=oelevpy_capi) {
    Py_XDECREF(capi_oelevpy_tmp); }
  }  /*if (capi_oelevpy_tmp == NULL) ... else of oelevpy*/
  /* End of cleaning variable oelevpy */
  } /*if (f2py_success) of maxthpy*/
  /* End of cleaning variable maxthpy */
  } /*if (f2py_success) of coeffpy*/
  /* End of cleaning variable coeffpy */
  } /*if (f2py_success) of nsteppy*/
  /* End of cleaning variable nsteppy */
  } /*if (f2py_success) of tsteppy*/
  /* End of cleaning variable tsteppy */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/**************************** end of wavdiffusion ****************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"airymodel",-1,{{-1}},0,(char *)F_FUNC(airymodel,AIRYMODEL),(f2py_init_func)f2py_rout_waveseds_airymodel,doc_f2py_rout_waveseds_airymodel},
  {"wavtransport",-1,{{-1}},0,(char *)F_FUNC(wavtransport,WAVTRANSPORT),(f2py_init_func)f2py_rout_waveseds_wavtransport,doc_f2py_rout_waveseds_wavtransport},
  {"wavdiffusion",-1,{{-1}},0,(char *)F_FUNC(wavdiffusion,WAVDIFFUSION),(f2py_init_func)f2py_rout_waveseds_wavdiffusion,doc_f2py_rout_waveseds_wavdiffusion},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "waveseds",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_waveseds(void) {
#else
#define RETVAL
PyMODINIT_FUNC initwaveseds(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = waveseds_module = PyModule_Create(&moduledef);
#else
  m = waveseds_module = Py_InitModule("waveseds", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module waveseds (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'waveseds' is auto-generated with f2py (version:2).\nFunctions:\n"
"  pc,pl,ptravel,pwaveh = airymodel(pdx,pdd,ph0,pdepth,psrc,pinland,pshadow,pnumrow=shape(pdepth,0),pnumcol=shape(pdepth,1))\n"
"  pydz,pydist = wavtransport(pyits,pydepth,pyhent,pytransx,pytransy,pynrow=shape(pydepth,0),pyncol=shape(pydepth,1))\n"
"  depopy = wavdiffusion(oelevpy,dzpy,coeffpy,maxthpy,tsteppy,nsteppy,numrowpy=shape(oelevpy,0),numcolpy=shape(oelevpy,1))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  waveseds_error = PyErr_NewException ("waveseds.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));



/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"waveseds");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
