#include <sstream>
#include <cstddef>
#include <disenum/env_obj_appear_linear_marker.h>

namespace DIS {

namespace env_obj_appear_linear_marker {

  bitmask& bitmask::operator=(const unsigned int& i) {
    (*this) = *( reinterpret_cast<bitmask *> (const_cast<unsigned int*>(&i))) ;
	  return (*this);
  }

  bitmask::bitmask(const unsigned int& i) {
    (*this) = i ;
  }

  bitmask::bitmask() {
    (*this) = (unsigned int) 0;
  }

  unsigned int bitmask::getValue(){
    unsigned int val = *( reinterpret_cast<unsigned int *> (this));
    return val;
  }

  void bitmask::setValue(const unsigned int& i){
	  (*this) = i;
  }

	/*
	 **  VisibleSide implementation **
	 */

	hashMap<int,VisibleSide*> VisibleSide::enumerations;
	short VisibleSide::startBit = 16;
	short VisibleSide::endBit   = 17;

 VisibleSide VisibleSide::LEFT_SIDE_IS_VISIBLE(0, "Left side is visible");
 VisibleSide VisibleSide::RIGHT_SIDE_IS_VISIBLE(1, "Right side is visible");
 VisibleSide VisibleSide::BOTH_SIDES_ARE_VISIBLE(2, "Both sides are visible");


	VisibleSide::VisibleSide(int value, std::string description) :
	  Enumeration(value, description)
	{
	  enumerations[value] = this;
	};

	VisibleSide* VisibleSide::findEnumeration(int aVal) {
	  VisibleSide* pEnum;

	  enumContainer::iterator enumIter = enumerations.find(aVal);
	  if (enumIter == enumerations.end()) pEnum = NULL;
	  else pEnum = (*enumIter).second;
	  return pEnum;
	};

	std::string VisibleSide::getDescriptionForValue(int aVal) {
	  VisibleSide* pEnum = findEnumeration(aVal);
	  if (pEnum) return pEnum->description;
	  else {
		std::stringstream ss;
		ss <<  "Invalid enumeration: " << aVal;
		return (ss.str());
	  }
	};

	VisibleSide VisibleSide::getEnumerationForValue(int aVal) throw(EnumException) {
	  VisibleSide* pEnum = findEnumeration(aVal);
	  if (pEnum) return (*pEnum);
	  else  {
		std::stringstream ss;
		ss << "No enumeration found for value " << aVal << " of enumeration VisibleSide";
		throw EnumException("VisibleSide", aVal, ss.str());
	  }
	};

	bool VisibleSide::enumerationForValueExists(int aVal) {
	  VisibleSide* pEnum = findEnumeration(aVal);
	  if (pEnum) return (true);
	  else       return (false);
	};

	VisibleSide::enumContainer VisibleSide::getEnumerations() {
	  return (enumerations);
	};





}; /* namespace env_obj_appear_linear_marker */

} /* namespace DIS */
