#include <CORA/CORA.h>
#include <CORA/CORA_problem.h>
#include <CORA/CORA_types.h>
#include <CORA/pyfg_text_parser.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage " << argv[0] << " [input .g2o/.pyfg file]" << std::endl;
        exit(1);
    }
}