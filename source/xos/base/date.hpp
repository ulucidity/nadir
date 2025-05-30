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
///   File: date.hpp
///
/// Author: $author$
///   Date: 1/3/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_BASE_DATE_HPP
#define XOS_BASE_DATE_HPP

#include "xos/base/time.hpp"

namespace xos {

/// class datet
template <class TExtends = time, class TImplements = typename TExtends::implements>
class exported datet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef datet derives;

    /// constructor / destructor
    datet(years_t year, months_t month, days_t day)
        : year_(year), month_(month), day_(day) {
    }
    datet(const datet &copy)
        : year_(copy.year()), month_(copy.month()), day_(copy.day()) {
    }
    datet() {
    }
    virtual ~datet() {
    }

    /// clear... / set...
    virtual datet& clear() {
        extends::clear();
        set_year(0);
        return *this;
    }
    virtual years_t set_year(years_t to) {
        year_= to;
        set_month(0);
        return year_;
    }
    virtual years_t year() const {
        return year_;
    }
    virtual months_t set_month(months_t to) {
        month_= to;
        set_day(0);
        return month_;
    }
    virtual months_t month() const {
        return month_;
    }
    virtual days_t set_day(days_t to) {
        day_= to;
        this->set_hour(0);
        return day_;
    }
    virtual days_t day() const {
        return day_;
    }

    /// compare...
    virtual int compare(const datet& to) const {
        return compare_date(to);
    }
    virtual int compare_date(const datet& to) const {
        int unequal = 0;
        if (!(unequal = compare_year(to.year()))) {
            if (!(unequal = compare_month(to.month()))) {
                if (!(unequal = compare_day(to.day()))) {
                    unequal = this->compare_time(to);
                }
            }
        }
        return unequal;
    }
    virtual int compare_year(years_t to) const {
        if ((year_ < to)) {
            return -1;
        } else {
            if ((year_ > to)) {
                return 1;
            }
        }
        return 0;
    }
    virtual int compare_month(months_t to) const {
        if ((month_ < to)) {
            return -1;
        } else {
            if ((month_ > to)) {
                return 1;
            }
        }
        return 0;
    }
    virtual int compare_day(days_t to) const {
        if ((day_ < to)) {
            return -1;
        } else {
            if ((day_ > to)) {
                return 1;
            }
        }
        return 0;
    }
    virtual int operator != (const datet& to) const {
        return this->compare(to);
    }
    virtual operator bool () const {
        const datet to;
        return ((this->compare(to)) != 0);
    }

protected:
    years_t year_;
    months_t month_;
    days_t day_;
}; /// class datet
typedef datet<> date;

} /// namespace xos 

#endif /// ndef XOS_BASE_DATE_HPP
