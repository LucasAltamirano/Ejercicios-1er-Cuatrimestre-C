/*
 * parser.h
 *
 *  Created on: 8 jun. 2021
 *      Author: Lucas
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListaLibros);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);



#endif /* PARSER_H_ */
