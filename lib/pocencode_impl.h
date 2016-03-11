/* Written by Brandon Creighton <cstone@pobox.com>.
 *
 * This code is in the public domain; however, note that most of its
 * dependent code, including GNU Radio, is not.
 */

#ifndef INCLUDED_MIXALOT_POCENCODE_IMPL_H
#define INCLUDED_MIXALOT_POCENCODE_IMPL_H

#include <mixalot/pocencode.h>
#include <queue>
#include <itpp/comm/bch.h>

using namespace itpp;
using std::string;
using boost::shared_ptr;


namespace gr {
  namespace mixalot {
      
    class pocencode_impl : public pocencode
    {
    private:
        std::queue<bool> d_bitqueue;   // Queue of symbols to be sent out.
        unsigned int d_batch_counter;   // batch counter between each 576bit 01010101....
        bool d_capfinder;               // capfinder mode
        msgtype_t d_msgtype;                // message type
        unsigned int d_baudrate;            // baud rate to transmit at -- should be 512, 1200, or 2400 (although others will work!)
        unsigned int d_start_capcode;       // capfinder mode start capcode
        unsigned int d_end_capcode;         // capfinder mode end capcode
        unsigned int d_cap_step;            // capfinder mode cap step
        unsigned int d_cur_capcode;         // capfinder mode current capcode
        unsigned int d_capcode;             // capcode (pager ID)
        pager_lang_t d_pager_lang;          // pager language type;
        unsigned long d_symrate;            // output symbol rate (must be evenly divisible by the baud rate)
        std::string d_message;              // message to send
        char d_capcode_message[16];         // message contain the capcode
        
        inline void queuebit(bool bit);

    public:
        pocencode_impl(bool capfinder, msgtype_t msgtype, unsigned int baudrate, unsigned int start_capcode, unsigned int end_capcode, unsigned int cap_step, unsigned int capcode, pager_lang_t pager_lang, std::string message, unsigned long symrate);
      ~pocencode_impl();

      // Where all the action really happens
        void queue_batch();
        void queue(shared_ptr<bvec> bvptr);
        void queue(gr_uint32 val);
        int work(int noutput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };


  } // namespace mixalot
} // namespace gr

#endif /* INCLUDED_MIXALOT_POCENCODE_IMPL_H */

