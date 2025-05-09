//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: timezone.hpp
///
/// Author: $author$
///   Date: 1/3/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_BASE_TIMEZONE_HPP
#define XOS_BASE_TIMEZONE_HPP

#include "xos/base/base.hpp"

namespace xos {

/// class timezonet
template <class TExtends = extend, class TImplements = implement>
class exported timezonet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef timezonet derives;

    /// constructor / destructor
    timezonet(const timezonet &copy): extends(copy) {
    }
    timezonet() {
    }
    virtual ~timezonet() {
    }
private:
public:

protected:
}; /// class timezonet
typedef timezonet<> timezone;
typedef timezone* timezone_t;

} /// namespace xos 

#endif /// ndef XOS_BASE_TIMEZONE_HPP
