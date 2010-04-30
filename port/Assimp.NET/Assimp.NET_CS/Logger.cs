/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class Logger : AllocateFromAssimpHeap {
  private HandleRef swigCPtr;

  internal Logger(IntPtr cPtr, bool cMemoryOwn) : base(AssimpPINVOKE.LoggerUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(Logger obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~Logger() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AssimpPINVOKE.delete_Logger(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public void debug(string message) {
    AssimpPINVOKE.Logger_debug(swigCPtr, message);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void info(string message) {
    AssimpPINVOKE.Logger_info(swigCPtr, message);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void warn(string message) {
    AssimpPINVOKE.Logger_warn(swigCPtr, message);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void error(string message) {
    AssimpPINVOKE.Logger_error(swigCPtr, message);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void setLogSeverity(Logger.LogSeverity log_severity) {
    AssimpPINVOKE.Logger_setLogSeverity(swigCPtr, (int)log_severity);
  }

  public Logger.LogSeverity getLogSeverity() {
    Logger.LogSeverity ret = (Logger.LogSeverity)AssimpPINVOKE.Logger_getLogSeverity(swigCPtr);
    return ret;
  }

  public virtual bool attachStream(LogStream pStream, uint severity) {
    bool ret = AssimpPINVOKE.Logger_attachStream__SWIG_0(swigCPtr, LogStream.getCPtr(pStream), severity);
    return ret;
  }

  public virtual bool attachStream(LogStream pStream) {
    bool ret = AssimpPINVOKE.Logger_attachStream__SWIG_1(swigCPtr, LogStream.getCPtr(pStream));
    return ret;
  }

  public virtual bool detatchStream(LogStream pStream, uint severity) {
    bool ret = AssimpPINVOKE.Logger_detatchStream__SWIG_0(swigCPtr, LogStream.getCPtr(pStream), severity);
    return ret;
  }

  public virtual bool detatchStream(LogStream pStream) {
    bool ret = AssimpPINVOKE.Logger_detatchStream__SWIG_1(swigCPtr, LogStream.getCPtr(pStream));
    return ret;
  }

  public enum LogSeverity {
    NORMAL,
    VERBOSE
  }

  public enum ErrorSeverity {
    DEBUGGING = 1,
    INFO = 2,
    WARN = 4,
    ERR = 8
  }

}