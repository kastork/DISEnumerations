#ifndef STATEUPDATEINDICATOR__H
#define STATEUPDATEINDICATOR__H

#include <string>
#include <disenum/Enumeration.h>

namespace DIS {

class StateUpdateIndicator : public Enumeration {
  public:
    static StateUpdateIndicator STATE_UPDATE;
    static StateUpdateIndicator CHANGED_DATA_UPDATE;
    

    /** Returns the string description associated with the enumerated instance with this value.
     * If there is no enumerated instance for this value, the string Invalid enumeration: <val> is returned.     */
    static std::string getDescriptionForValue(int aVal);

    /** Returns the enumerated instance with this value.
     * If there is no enumerated instance for this value, the exception is thrown.     */
    static StateUpdateIndicator getEnumerationForValue(int aVal) throw(EnumException);

    /** Returns true if there is an enumerated instance for this value, false otherwise. */
    static bool enumerationForValueExists(int aVal);

    typedef hashMap<int,StateUpdateIndicator*> enumContainer;
    static enumContainer getEnumerations();

    StateUpdateIndicator& operator=(const int& aVal) throw(EnumException);

  private:
    /** Constructor */
	  StateUpdateIndicator(int value, std::string description);

	  static StateUpdateIndicator* findEnumeration(int aVal);
    static enumContainer enumerations;

};  /* StateUpdateIndicator */


}  /* namespace DIS */

#endif /* STATEUPDATEINDICATOR__H */

