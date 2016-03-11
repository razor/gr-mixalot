/* Written by Brandon Creighton <cstone@pobox.com>.
 *
 * This code is in the public domain; however, note that most of its
 * dependent code, including GNU Radio, is not.
 */

#ifndef INCLUDED_MIXALOT_POCENCODE_H
#define INCLUDED_MIXALOT_POCENCODE_H

#include <mixalot/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace mixalot {


    class MIXALOT_API pocencode : virtual public sync_block
    {
    public:
       typedef boost::shared_ptr<pocencode> sptr;
       typedef enum { Numeric = 0, Alpha = 1 } msgtype_t;
       typedef enum { English = 0, Chinese = 1} pager_lang_t;

       static sptr make(bool capfinder = 0, msgtype_t type=Numeric, unsigned int baudrate = 1200, unsigned int start_capcode = 0, unsigned int end_capcode = 2097152, unsigned int cap_step = 0, unsigned int capcode = 0, pager_lang_t pager_lang = English, std::string message="", unsigned long symrate = 38400);
    };

  } // namespace mixalot
} // namespace gr

#endif /* INCLUDED_MIXALOT_POCENCODE_H */

