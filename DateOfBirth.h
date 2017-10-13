/*
 * DateOfBirth.h
 *
 *  Created on: 28.06.2017
 *      Author: 168625
 */

#ifndef DATEOFBIRTH_H_
#define DATEOFBIRTH_H_

class DateOfBirth
{
    short year;
    short month;
    short day;

  public:
    DateOfBirth(short, short, short);

    void changeDay(short);
    void changeMonth(short);
    void changeYear(short);

    short getDay() const;
    short getMonth() const;
    short getYear() const;

    void printDateOfBirth() const;
};

#endif /* DATEOFBIRTH_H_ */
