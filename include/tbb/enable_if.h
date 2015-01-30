//Author: Xuepeng Fan
#ifndef __TBB_enable_if_H
#define __TBB_enable_if_H

namespace tbb{
namespace internal{
template <bool flag, class T>
struct enable_if
{
  typedef T type;
};

template<class T>
struct enable_if<false, T>{};

}//end namespace internal
}//end namespace tbb


#endif
