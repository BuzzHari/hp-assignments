#ifndef __X10_REGIONARRAY_REMOTEARRAY_H
#define __X10_REGIONARRAY_REMOTEARRAY_H

#include <x10rt.h>


#define X10_LANG_GLOBALRAIL_H_NODEPS
#include <x10/lang/GlobalRail.h>
#undef X10_LANG_GLOBALRAIL_H_NODEPS
#define X10_LANG_GLOBALRAIL_H_NODEPS
#include <x10/lang/GlobalRail.h>
#undef X10_LANG_GLOBALRAIL_H_NODEPS
#define X10_LANG_LONG_H_NODEPS
#include <x10/lang/Long.h>
#undef X10_LANG_LONG_H_NODEPS
#define X10_LANG_LONG_H_NODEPS
#include <x10/lang/Long.h>
#undef X10_LANG_LONG_H_NODEPS
#define X10_LANG_GLOBALREF_H_NODEPS
#include <x10/lang/GlobalRef.h>
#undef X10_LANG_GLOBALREF_H_NODEPS
#define X10_LANG_GLOBALREF_H_NODEPS
#include <x10/lang/GlobalRef.h>
#undef X10_LANG_GLOBALREF_H_NODEPS
namespace x10 { namespace regionarray { 
class Region;
} } 
namespace x10 { namespace regionarray { 
template<class TPMGL(T)> class Array;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
namespace x10 { namespace lang { 
template<class TPMGL(T)> class Rail;
} } 
namespace x10 { namespace xrx { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class Point;
} } 
namespace x10 { namespace lang { 
class FailedDynamicCheckException;
} } 
namespace x10 { namespace lang { 
class Any;
} } 
namespace x10 { namespace compiler { 
class Synthetic;
} } 

namespace x10 { namespace regionarray { 

class RemoteArray_Strings {
  public:
    static ::x10::lang::String sl__157353;
};

template<class TPMGL(T)> class RemoteArray;
template <> class RemoteArray<void>;
template<class TPMGL(T)> class RemoteArray : public ::x10::lang::X10Class
  {
    public:
    RTT_H_DECLS_CLASS
    
    ::x10::regionarray::Region* FMGL(region);
    
    x10_long FMGL(size);
    
    ::x10::lang::GlobalRef< ::x10::regionarray::Array<TPMGL(T)>* > FMGL(array);
    
    ::x10::lang::GlobalRail<TPMGL(T)> FMGL(rawData);
    
    x10_long rank();
    ::x10::lang::Place home();
    void _constructor(::x10::regionarray::Array<TPMGL(T)>* a);
    
    static ::x10::regionarray::RemoteArray<TPMGL(T)>* _make(::x10::regionarray::Array<TPMGL(T)>* a);
    
    virtual TPMGL(T) __apply(x10_int i);
    virtual TPMGL(T) __apply(::x10::lang::Point* p);
    virtual TPMGL(T) __set(x10_int i, TPMGL(T) v);
    virtual TPMGL(T) __set(::x10::lang::Point* p, TPMGL(T) v);
    virtual ::x10::regionarray::Array<TPMGL(T)>* __apply();
    virtual x10_boolean equals(::x10::lang::Any* other);
    virtual x10_int hashCode();
    virtual ::x10::regionarray::RemoteArray<TPMGL(T)>* x10__regionarray__RemoteArray____this__x10__regionarray__RemoteArray(
      );
    virtual void __fieldInitializers_x10_regionarray_RemoteArray(
      );
    
    // Serialization
    public: static const ::x10aux::serialization_id_t _serialization_id;
    
    public: ::x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(::x10aux::serialization_buffer& buf);
    
    public: static ::x10::lang::Reference* _deserializer(::x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(::x10aux::deserialization_buffer& buf);
    
};

template<class TPMGL(T)> ::x10aux::RuntimeType x10::regionarray::RemoteArray<TPMGL(T)>::rtt;
template<class TPMGL(T)> void x10::regionarray::RemoteArray<TPMGL(T)>::_initRTT() {
    const ::x10aux::RuntimeType *canonical = ::x10aux::getRTT< ::x10::regionarray::RemoteArray<void> >();
    if (rtt.initStageOne(canonical)) return;
    const ::x10aux::RuntimeType** parents = NULL; 
    const ::x10aux::RuntimeType* params[1] = { ::x10aux::getRTT<TPMGL(T)>()};
    ::x10aux::RuntimeType::Variance variances[1] = { ::x10aux::RuntimeType::invariant};
    const char *baseName = "x10.regionarray.RemoteArray";
    rtt.initStageTwo(baseName, ::x10aux::RuntimeType::class_kind, 0, parents, 1, params, variances);
}

template <> class RemoteArray<void> : public ::x10::lang::X10Class
{
    public:
    static ::x10aux::RuntimeType rtt;
    static const ::x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_REGIONARRAY_REMOTEARRAY_H

namespace x10 { namespace regionarray { 
template<class TPMGL(T)> class RemoteArray;
} } 

#ifndef X10_REGIONARRAY_REMOTEARRAY_H_NODEPS
#define X10_REGIONARRAY_REMOTEARRAY_H_NODEPS
#include <x10/lang/GlobalRail.h>
#include <x10/lang/Long.h>
#include <x10/lang/GlobalRef.h>
#include <x10/regionarray/Region.h>
#include <x10/regionarray/Array.h>
#include <x10/lang/Place.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Int.h>
#include <x10/xrx/Runtime.h>
#include <x10/lang/Point.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/FailedDynamicCheckException.h>
#include <x10/lang/Any.h>
#include <x10/compiler/Synthetic.h>
#include <x10/lang/String.h>
#ifndef X10_REGIONARRAY_REMOTEARRAY_H_GENERICS
#define X10_REGIONARRAY_REMOTEARRAY_H_GENERICS
#endif // X10_REGIONARRAY_REMOTEARRAY_H_GENERICS
#ifndef X10_REGIONARRAY_REMOTEARRAY_H_IMPLEMENTATION
#define X10_REGIONARRAY_REMOTEARRAY_H_IMPLEMENTATION
#include <x10/regionarray/RemoteArray.h>


//#line 32 "x10/regionarray/RemoteArray.x10"
/**
         * The Region of the remote array
         */

//#line 36 "x10/regionarray/RemoteArray.x10"
/**
         * The size of the remote array.
         */

//#line 40 "x10/regionarray/RemoteArray.x10"
/**
         * The GlobalRef to the remote array.
         */

//#line 47 "x10/regionarray/RemoteArray.x10"
/**
     * Caches a remote reference to the backing storage for the remote array
     * to enable DMA operations to be initiated remotely.  
     */

//#line 52 "x10/regionarray/RemoteArray.x10"
/**
     * The rank of the RemoteArray is equal to region.rank
     */
template<class TPMGL(T)> x10_long x10::regionarray::RemoteArray<TPMGL(T)>::rank(
  ) {
    return ::x10aux::nullCheck(this->FMGL(region))->FMGL(rank);
    
}

//#line 57 "x10/regionarray/RemoteArray.x10"
/**
     * The home location of the RemoteArray is equal to array.home
     */
template<class TPMGL(T)> ::x10::lang::Place x10::regionarray::RemoteArray<TPMGL(T)>::home(
  ) {
    return ::x10::lang::Place::_make((this->FMGL(array))->location);
    
}

//#line 63 "x10/regionarray/RemoteArray.x10"
/**
     * Create a RemoteArray wrapping the argument local Array.
     * @param a The array object to make accessible remotely.
     */
template<class TPMGL(T)> void x10::regionarray::RemoteArray<TPMGL(T)>::_constructor(
                           ::x10::regionarray::Array<TPMGL(T)>* a) {
    
    //#line 64 "x10/regionarray/RemoteArray.x10"
    FMGL(region) = a->FMGL(region);
    FMGL(size) = a->FMGL(size);
    FMGL(array) = ::x10::lang::GlobalRef< ::x10::regionarray::Array<TPMGL(T)>* >(a);
    
    //#line 28 "x10/regionarray/RemoteArray.x10"
    this->x10::regionarray::template RemoteArray<TPMGL(T)>::__fieldInitializers_x10_regionarray_RemoteArray();
    
    //#line 65 "x10/regionarray/RemoteArray.x10"
    this->FMGL(rawData) = ::x10::lang::GlobalRail<TPMGL(T)>::_make(a->x10::regionarray::template Array<TPMGL(T)>::raw());
}
template<class TPMGL(T)> ::x10::regionarray::RemoteArray<TPMGL(T)>* x10::regionarray::RemoteArray<TPMGL(T)>::_make(
                           ::x10::regionarray::Array<TPMGL(T)>* a)
{
    ::x10::regionarray::RemoteArray<TPMGL(T)>* this_ = new (::x10aux::alloc_z< ::x10::regionarray::RemoteArray<TPMGL(T)> >()) ::x10::regionarray::RemoteArray<TPMGL(T)>();
    this_->_constructor(a);
    return this_;
}



//#line 79 "x10/regionarray/RemoteArray.x10"
/**
     * Return the element of this array corresponding to the given index.
     * Only applies to one-dimensional arrays.
     * Can only  be called where <code>here == array.home</code>. 
     * Functionally equivalent to indexing the array via a one-dimensional point.
     * 
     * @param i0 the given index in the first dimension
     * @return the element of this array corresponding to the given index.
     * @see #operator(Point)
     * @see #set(T, Int)
     */
template<class TPMGL(T)> TPMGL(T) x10::regionarray::RemoteArray<TPMGL(T)>::__apply(
  x10_int i) {
    return ::x10aux::nullCheck(this->x10::regionarray::template RemoteArray<TPMGL(T)>::__apply())->x10::regionarray::template Array<TPMGL(T)>::__apply(
             ((x10_long)(i)));
    
}

//#line 91 "x10/regionarray/RemoteArray.x10"
/**
     * Return the element of this array corresponding to the given point.
     * The rank of the given point has to be the same as the rank of this array.
     * Can only  be called where <code>here == array.home</code>. 
     * 
     * @param pt the given point
     * @return the element of this array corresponding to the given point.
     * @see #operator(Int)
     * @see #set(T, Point)
     */
template<class TPMGL(T)> TPMGL(T) x10::regionarray::RemoteArray<TPMGL(T)>::__apply(
  ::x10::lang::Point* p) {
    return ::x10aux::nullCheck(this->x10::regionarray::template RemoteArray<TPMGL(T)>::__apply())->x10::regionarray::template Array<TPMGL(T)>::__apply(
             p);
    
}

//#line 106 "x10/regionarray/RemoteArray.x10"
/**
     * Set the element of this array corresponding to the given index to the given value.
     * Return the new value of the element.
     * Only applies to one-dimensional arrays.
     * Can only  be called where <code>here == array.home</code>. 
     * Functionally equivalent to setting the array via a one-dimensional point.
     * 
     * @param v the given value
     * @param i0 the given index in the first dimension
     * @return the new value of the element of this array corresponding to the given index.
     * @see #operator(Int)
     * @see #set(T, Point)
     */
template<class TPMGL(T)> TPMGL(T) x10::regionarray::RemoteArray<TPMGL(T)>::__set(
  x10_int i, TPMGL(T) v) {
    return ::x10aux::nullCheck(this->x10::regionarray::template RemoteArray<TPMGL(T)>::__apply())->x10::regionarray::template Array<TPMGL(T)>::__set(
             ((x10_long)(i)), v);
    
}

//#line 120 "x10/regionarray/RemoteArray.x10"
/**
     * Set the element of this array corresponding to the given point to the given value.
     * Return the new value of the element.
     * The rank of the given point has to be the same as the rank of this array.
     * Can only  be called where <code>here == array.home</code>. 
     * 
     * @param v the given value
     * @param p the given point
     * @return the new value of the element of this array corresponding to the given point.
     * @see #operator(Point)
     * @see #set(T, Int)
     */
template<class TPMGL(T)> TPMGL(T) x10::regionarray::RemoteArray<TPMGL(T)>::__set(
  ::x10::lang::Point* p, TPMGL(T) v) {
    
    //#line 121 "x10/regionarray/RemoteArray.x10"
    return ::x10aux::nullCheck(this->x10::regionarray::template RemoteArray<TPMGL(T)>::__apply())->x10::regionarray::template Array<TPMGL(T)>::__set(
             p, v);
    
}

//#line 128 "x10/regionarray/RemoteArray.x10"
/**
     * Access the Array that is encapsulated by this RemoteArray. 
     * Can only  be called where <code>here == array.home</code>. 
     */
template<class TPMGL(T)> ::x10::regionarray::Array<TPMGL(T)>*
  x10::regionarray::RemoteArray<TPMGL(T)>::__apply() {
    ::x10::regionarray::Array<TPMGL(T)>* t__119786 = (this->FMGL(array))->__apply();
    if (!((::x10aux::struct_equals(::x10aux::nullCheck(t__119786)->FMGL(rank),
                                   ::x10aux::nullCheck(::x10aux::nullCheck(this)->FMGL(region))->FMGL(rank)))))
    {
        ::x10aux::throwException(::x10aux::nullCheck(::x10::lang::FailedDynamicCheckException::_make((&::x10::regionarray::RemoteArray_Strings::sl__157353))));
    }
    return t__119786;
    
}

//#line 130 "x10/regionarray/RemoteArray.x10"
template<class TPMGL(T)> x10_boolean x10::regionarray::RemoteArray<TPMGL(T)>::equals(
  ::x10::lang::Any* other) {
    
    //#line 131 "x10/regionarray/RemoteArray.x10"
    if (!(::x10aux::instanceof< ::x10::regionarray::RemoteArray<TPMGL(T)>*>(other)))
    {
        return false;
        
    }
    
    //#line 132 "x10/regionarray/RemoteArray.x10"
    ::x10::regionarray::RemoteArray<TPMGL(T)>* oRA = ::x10aux::class_cast< ::x10::regionarray::RemoteArray<TPMGL(T)>*>(other);
    
    //#line 133 "x10/regionarray/RemoteArray.x10"
    return (::x10aux::nullCheck(oRA)->FMGL(array))->equals(::x10aux::class_cast_unchecked< ::x10::lang::Any*>(this->FMGL(array)));
    
}

//#line 136 "x10/regionarray/RemoteArray.x10"
template<class TPMGL(T)> x10_int x10::regionarray::RemoteArray<TPMGL(T)>::hashCode(
  ) {
    return (this->FMGL(array))->hashCode();
    
}

//#line 28 "x10/regionarray/RemoteArray.x10"
template<class TPMGL(T)> ::x10::regionarray::RemoteArray<TPMGL(T)>*
  x10::regionarray::RemoteArray<TPMGL(T)>::x10__regionarray__RemoteArray____this__x10__regionarray__RemoteArray(
  ) {
    return this;
    
}
template<class TPMGL(T)> void x10::regionarray::RemoteArray<TPMGL(T)>::__fieldInitializers_x10_regionarray_RemoteArray(
  ) {
 
}
template<class TPMGL(T)> const ::x10aux::serialization_id_t x10::regionarray::RemoteArray<TPMGL(T)>::_serialization_id = 
    ::x10aux::DeserializationDispatcher::addDeserializer(::x10::regionarray::RemoteArray<TPMGL(T)>::_deserializer);

template<class TPMGL(T)> void x10::regionarray::RemoteArray<TPMGL(T)>::_serialize_body(::x10aux::serialization_buffer& buf) {
    buf.write(this->FMGL(rawData));
    buf.write(this->FMGL(region));
    buf.write(this->FMGL(size));
    buf.write(this->FMGL(array));
    
}

template<class TPMGL(T)> ::x10::lang::Reference* ::x10::regionarray::RemoteArray<TPMGL(T)>::_deserializer(::x10aux::deserialization_buffer& buf) {
    ::x10::regionarray::RemoteArray<TPMGL(T)>* this_ = new (::x10aux::alloc_z< ::x10::regionarray::RemoteArray<TPMGL(T)> >()) ::x10::regionarray::RemoteArray<TPMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class TPMGL(T)> void x10::regionarray::RemoteArray<TPMGL(T)>::_deserialize_body(::x10aux::deserialization_buffer& buf) {
    FMGL(rawData) = buf.read< ::x10::lang::GlobalRail<TPMGL(T)> >();
    FMGL(region) = buf.read< ::x10::regionarray::Region*>();
    FMGL(size) = buf.read<x10_long>();
    FMGL(array) = buf.read< ::x10::lang::GlobalRef< ::x10::regionarray::Array<TPMGL(T)>* > >();
}

#endif // X10_REGIONARRAY_REMOTEARRAY_H_IMPLEMENTATION
#endif // __X10_REGIONARRAY_REMOTEARRAY_H_NODEPS
