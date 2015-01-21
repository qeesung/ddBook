#include <iostream>
#include <vector>
#include <string>
#include "book.pb.h"
#include "createBasicDataTable.h"
#include "createModeTable.h"
#include "createIndexDataTable.h"
#include "createNode.h"
#include "createTree.h"
#include "transferMechanism.h"

using namespace std;

int main(int argc, char const *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	if (argc != 2) {
	    cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
	    return -1;
	}
	ddBook::Book book;

	{
	    fstream input(argv[1], ios::in | ios::binary);
	    if (!book.ParseFromIstream(&input)) {
	      cerr << "Failed to parse address book." << endl;
	      return -1;
	    }
    }
    stateTransfer(&book,0);
	return 0;
}