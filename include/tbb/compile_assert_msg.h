//Author: Xuepeng Fan
#ifndef __TBB_compile_assert_msg_H
#define __TBB_compile_assert_msg_H



#if __cplusplus >= 201103L 
#define __USING_TBB_WITH_CPP11
#include <type_traits>
#endif
#include "tbb_stddef.h"
#include "enable_if.h"

namespace tbb{
  namespace internal{

#ifdef __USING_TBB_WITH_CPP11
    template <class T>
      struct is_atomic_compatiable{
        //typedef  bool_constant<std::is_enum<T>::value || std::is_integral<T>::value || std::is_pointer<T>::value> type;
        const static bool value = std::is_enum<T>::value || std::is_integral<T>::value || std::is_pointer<T>::value;
      };

    template <class T>
      struct is_copyable_class{
        const static bool value = std::is_copy_constructible<T>::value;
      };
    template<class FT>
      struct is_const_method{
        const static bool value = false;
      };
    template<class Ret, class C, class... Args>
      struct is_const_method<Ret (C::*)(Args...) const>
      {
        const static bool value = true;
      };

    template<class T>
      struct is_operator_const{
        typedef decltype(&std::remove_reference<T>::type::operator()) op_type;
        const static bool value = is_const_method<op_type>::value;
      };

    template <class T>
      struct check_the_assert_message{
        const static bool value = false;
      };

#else
    //We only do the compile-check for c++11
    template <class T>
      struct is_atomic_compatiable{
        //typedef bool_constant<true> type;
        const static bool value = true;
      };

    template<class T>
      struct check_the_assert_message{
        const static bool value = true;
      };

    template<class T>
      struct is_copyable_class{
        const static bool value = true;
      };

    template<class T>
      struct is_operator_const{
        const static bool value = true;
      };

#endif

#define __TBB_ASSERT_MSG_NOT_SUPPORT_ATOMIC_TYPE "tbb::atomic only supports integral type, enumeration type and pointer type!"
#define __TBB_ASSERT_MSG_PARALLEL_REDUECE_BODY_SHOULD_BE_REFERENCE_INSTEAD_OF_POINTER "the second parameter of parallel_reduce should be reference instead of pointer" 
#define __TBB_ASSERT_MSG_PARALLEL_FOR_BODY_SHOULD_BE_COPYABLE "the second parameter of parallel_for must be copyable"

#define __TBB_ASSERT_MSG_PARALLEL_FOR_BODY_SHOULD_HAVE_CONST_OPERATOR "the second parameter of parallel_for must have operator()(...) as 'const', i.e., operator()(...) const"

#ifdef __USING_TBB_WITH_CPP11
#define STATIC_ASSERT(v, msg) static_assert(v, msg);
#else
#define STATIC_ASSERT(v, msg) 
#endif

  }//end namespace internal
}//end namespace tbb

#endif
