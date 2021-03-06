/* Arduino SdFat Library
 * Copyright (C) 2012 by William Greiman
 *
 * This file is part of the Arduino SdFat Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino SdFat Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef istream_h
#define istream_h
/**
 * \file
 * \brief \ref istream class
 */
#include <ios.h>

/**
 * \class istream
 * \brief Input Stream
 */
class istream : public virtual ios {
 public:
  istream() {}
  /** call manipulator
   * \param[in] pf function to call
   * \return the stream
   */
  istream& operator>>(istream& (*pf)(istream& str)) {
    return pf(*this);
  }
  /** call manipulator
   * \param[in] pf function to call
   * \return the stream
   */
  istream& operator>>(ios_base& (*pf)(ios_base& str)) {
    pf(*this);
    return *this;
  }
  /** call manipulator
   * \param[in] pf function to call
   * \return the stream
   */
  istream& operator>>(ios& (*pf)(ios& str)) {
    pf(*this);
    return *this;
  }
 /**
  * Extract a character string
  * \param[out] str location to store the string.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream& operator>>(char *str) {
    getStr(str);
    return *this;
  }
 /**
  * Extract a character
  * \param[out] ch location to store the character.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream& operator>>(char& ch) {
    getChar(&ch);
    return *this;
  }
 /**
  * Extract a character string
  * \param[out] str location to store the string.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream& operator>>(signed char *str) {
    getStr(reinterpret_cast<char*>(str));
    return *this;
  }
 /**
  * Extract a character
  * \param[out] ch location to store the character.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream& operator>>(signed char& ch) {
    getChar(reinterpret_cast<char*>(&ch));
    return *this;
  }
 /**
  * Extract a character string
  * \param[out] str location to store the string.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream& operator>>(unsigned char *str) {
    getStr(reinterpret_cast<char*>(str));
    return *this;
  }
 /**
  * Extract a character
  * \param[out] ch location to store the character.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream& operator>>(unsigned char& ch) {
    getChar(reinterpret_cast<char*>(&ch));
    return *this;
  }
 /**
  * Extract a value of type bool.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream& operator>>(bool& arg) {
    getBool(&arg);
    return *this;
  }
 /**
  * Extract a value of type short.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>>(short& arg) {  // NOLINT
    getNumber(&arg);
    return *this;
  }
 /**
  * Extract a value of type unsigned short.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>>(unsigned short& arg) {  // NOLINT
    getNumber(&arg);
    return *this;
  }
 /**
  * Extract a value of type int.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>>(int& arg) {
    getNumber(&arg);
    return *this;
  }
 /**
  * Extract a value of type unsigned int.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>>(unsigned int& arg) {
    getNumber(&arg);
    return *this;
  }
 /**
  * Extract a value of type long.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>>(long& arg) {  // NOLINT
    getNumber(&arg);
    return *this;
  }
 /**
  * Extract a value of type unsigned long.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>>(unsigned long& arg) {  // NOLINT
    getNumber(&arg);
    return *this;
  }
   /**
  * Extract a value of type double.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>> (double& arg) {
    getDouble(&arg);
    return *this;
  }
 /**
  * Extract a value of type float.
  * \param[out] arg location to store the value.
  * \return Is always *this.  Failure is indicated by the state of *this.
  */
  istream &operator>> (float& arg) {
    double v;
    getDouble(&v);
    arg = v;
    return *this;
  }
  /**
   * Extract a value of type void*.
   * \param[out] arg location to store the value.
   * \return Is always *this.  Failure is indicated by the state of *this.
   */
  istream& operator>> (void*& arg) {
    uint32_t val;
    getNumber(&val);
    arg = reinterpret_cast<void*>(val);
    return *this;
  }
  /**
   * \return The number of characters extracted by the last unformatted
   * input function.
   */
  streamsize gcount() const {return m_gcount;}
  int get();
  istream& get(char& ch);
  istream& get(char *str, streamsize n, char delim = '\n');
  istream& getline(char *str, streamsize count, char delim = '\n');
  istream& ignore(streamsize n = 1, int delim= -1);
  int peek();
// istream& read(char *str, streamsize count);
// streamsize readsome(char *str, streamsize count);
  /**
   * \return the stream position
   */
  pos_type tellg() {return tellpos();}
  /**
   * Set the stream position
   * \param[in] pos The absolute position in which to move the read pointer.
   * \return Is always *this.  Failure is indicated by the state of *this.
   */
  istream& seekg(pos_type pos) {
    if (!seekpos(pos)) setstate(failbit);
    return *this;
  }
  /**
   * Set the stream position.
   *
   * \param[in] off An offset to move the read pointer relative to way.
   * \a off is a signed 32-bit int so the offset is limited to +- 2GB.
   * \param[in] way One of ios::beg, ios::cur, or ios::end.
   * \return Is always *this.  Failure is indicated by the state of *this.
   */
  istream& seekg(off_type off, seekdir way) {
    if (!seekoff(off, way)) setstate(failbit);
    return *this;
  }
  void skipWhite();

 protected:
  /// @cond SHOW_PROTECTED
   /**
   * Internal - do not use
   * \return
   */
  virtual int16_t getch() = 0;
  /**
   * Internal - do not use
   * \param[out] pos
   * \return
   */
  int16_t getch(FatPos_t* pos) {
    getpos(pos);
    return getch();
  }
  /**
   * Internal - do not use
   * \param[out] pos
   */
  virtual void getpos(FatPos_t* pos) = 0;
  /**
   * Internal - do not use
   * \param[in] pos
   */
  virtual bool seekoff(off_type off, seekdir way) = 0;
  virtual bool seekpos(pos_type pos) = 0;
  virtual void setpos(FatPos_t* pos) = 0;
  virtual pos_type tellpos() = 0;

  /// @endcond
 private:
  void getBool(bool *b);
  void getChar(char* ch);
  bool getDouble(double* value);
  template <typename T>  void getNumber(T* value);
  bool getNumber(uint32_t posMax, uint32_t negMax, uint32_t* num);
  void getStr(char *str);
  int16_t readSkip();

  size_t m_gcount;
};
//------------------------------------------------------------------------------
template <typename T>
void istream::getNumber(T* value) {
  uint32_t tmp;
  if ((T)-1 < 0) {
    // number is signed, max positive value
    uint32_t const m = ((uint32_t)-1) >> (33 - sizeof(T) * 8);
    // max absolute value of negative number is m + 1.
    if (getNumber(m, m + 1, &tmp)) {
      *value = (T)tmp;
    }
  } else {
    // max unsigned value for T
    uint32_t const m = (T)-1;
    if (getNumber(m, m, &tmp)) {
      *value = (T)tmp;
    }
  }
}
#endif  // istream_h
