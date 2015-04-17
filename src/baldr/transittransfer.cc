#include "baldr/transittransfer.h"

namespace valhalla {
namespace baldr {

// Constructor with arguments
TransitTransfer::TransitTransfer(const uint32_t from_stopid,
                                 const uint32_t to_stopid,
                                 const TransferType type,
                                 const uint32_t mintime)
    : from_stopid_(from_stopid),
      to_stopid_(to_stopid) {
  transfer_.type = static_cast<uint32_t>(type);
  transfer_.mintime = mintime;
}

// Get the from stop Id.
uint32_t TransitTransfer::from_stopid() const {
  return from_stopid_;
}

// Get the to stop Id.
uint32_t TransitTransfer::to_stopid() const {
  return to_stopid_;
}

// Gets the transfer type.
TransferType TransitTransfer::type() const {
  return static_cast<TransferType>(transfer_.type);
}

// Get the minimum time (seconds) to make the transfer.
uint32_t TransitTransfer::mintime() const {
  return transfer_.mintime;
}

// operator < - for sorting. Sort by from stop Id and to stop Id.
bool TransitTransfer::operator < (const TransitTransfer& other) const {
  if (from_stopid() == other.from_stopid()) {
    return to_stopid() < other.to_stopid();
  } else {
    return from_stopid() < other.from_stopid();
  }
}

}
}
