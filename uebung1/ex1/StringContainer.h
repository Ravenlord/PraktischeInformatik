/* 
 * File:   StringContainer.h
 * Author: Markus Deutschl
 *
 * Created on October 29, 2012, 5:00 PM
 */
#include <string>
#include <sstream>
#ifndef STRINGCONTAINER_H
#define	STRINGCONTAINER_H

class StringContainer {
public:
  StringContainer() {}
  StringContainer(std::string s): value(s){}
  virtual ~StringContainer(){}
  
  // Getter and Setter for the value
  std::string get_value(){
    return value;
  }
  void set_value(std::string s){
    value = s;
  }
  
  // overload comparison operators
  friend bool operator== (StringContainer &sc1, StringContainer &sc2){
    return sc1.get_value().compare(sc2.get_value()) == 0 ? true : false;
  }
  friend bool operator!= (StringContainer &sc1, StringContainer &sc2){
    return sc1.get_value().compare(sc2.get_value()) != 0 ? true : false;
  }
  friend bool operator> (StringContainer &sc1, StringContainer &sc2) {
    return sc1.get_value().compare(sc2.get_value()) > 0 ? true : false;
  }
  friend bool operator< (StringContainer &sc1, StringContainer &sc2) {
    return sc1.get_value().compare(sc2.get_value()) < 0 ? true : false;
  }
  friend bool operator>= (StringContainer &sc1, StringContainer &sc2) {
    return sc1.get_value().compare(sc2.get_value()) >= 0 ? true : false;
  }
  friend bool operator<= (StringContainer &sc1, StringContainer &sc2) {
    return sc1.get_value().compare(sc2.get_value()) <= 0 ? true : false;
  }
  // overload stream operator for 'cout' printing
  friend std::ostream& operator<< (std::ostream &stream, StringContainer &sc) {
    return stream << sc.get_value();
  }
private:
  std::string value;
};

#endif	/* STRINGCONTAINER_H */

