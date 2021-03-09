#ifndef INSIDER_H
#define INSIDER_H

#include <string>
#include <vector>
#include "common.h"
#include "tinyxml2.h"

typedef tinyxml2::XMLElement xmldoc;
typedef struct
{
    std::string issuerCik;
    std::string issuerName;
    std::string issuerSym;
    std::string rptOwnerCik;
    std::string rptOwnerName;
    std::string rptOwnerRelation;
} filing_header;

typedef struct {
    std::vector<std::string> issuerCik;
    std::vector<std::string> issuerName;
    std::vector<std::string> issuerSym;
    std::vector<std::string> rptOwnerCik;
    std::vector<std::string> rptOwnerName;
    std::vector<std::string> rptOwnerRelation;

} transactions;

class Insider
{
private:
    std::string url;
    filing_header fheader;
    transactions ins_txns;

    void setHeader(xmldoc *doc);
    void getNonDerivativeTransactions(xmldoc* doc);


public:
    Insider(std::string url) : url{url} {};
    void getTransactions();
    void printTransactions();
};
#endif
