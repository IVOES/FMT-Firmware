

#define CANARD_DSDLC_INTERNAL
#include <dronecan.remoteid.SecureCommand_res.h>

#include <string.h>

#ifdef CANARD_DSDLC_TEST_BUILD
#include <test_helpers.h>
#endif

uint32_t dronecan_remoteid_SecureCommandResponse_encode(struct dronecan_remoteid_SecureCommandResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
) {
    uint32_t bit_ofs = 0;
    memset(buffer, 0, DRONECAN_REMOTEID_SECURECOMMAND_RESPONSE_MAX_SIZE);
    _dronecan_remoteid_SecureCommandResponse_encode(buffer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    tao
#else
    true
#endif
    );
    return ((bit_ofs+7)/8);
}

bool dronecan_remoteid_SecureCommandResponse_decode(const CanardRxTransfer* transfer, struct dronecan_remoteid_SecureCommandResponse* msg) {
    uint32_t bit_ofs = 0;
    _dronecan_remoteid_SecureCommandResponse_decode(transfer, &bit_ofs, msg, 
#if CANARD_ENABLE_TAO_OPTION
    transfer->tao
#else
    true
#endif
    );

    return (((bit_ofs+7)/8) != transfer->payload_len);
}

#ifdef CANARD_DSDLC_TEST_BUILD
struct dronecan_remoteid_SecureCommandResponse sample_dronecan_remoteid_SecureCommandResponse_msg(void) {

    struct dronecan_remoteid_SecureCommandResponse msg;






    msg.sequence = (uint32_t)random_bitlen_unsigned_val(32);







    msg.operation = (uint32_t)random_bitlen_unsigned_val(32);







    msg.result = (uint8_t)random_bitlen_unsigned_val(8);







    msg.data.len = (uint8_t)random_range_unsigned_val(0, 220);
    for (size_t i=0; i < msg.data.len; i++) {




        msg.data.data[i] = (uint8_t)random_bitlen_unsigned_val(8);



    }




    return msg;

}
#endif