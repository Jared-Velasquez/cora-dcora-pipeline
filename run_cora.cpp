#include <CORA/CORA.h>
#include <CORA/CORA_problem.h>
#include <CORA/CORA_types.h>
#include <CORA/CORA_utils.h>
#include <CORA/pyfg_text_parser.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Usage " << argv[0] << " [input .g2o/.pyfg file]" << " [output filepath]" << std::endl;
        exit(1);
    }

    CORA::Problem problem = CORA::parsePyfgTextToProblem(argv[1]);
    problem.updateProblemData();

    CORA::Matrix x0 = problem.getRandomInitialGuess();
    int max_rank = 10;

    CORA::CoraResult soln = CORA::solveCORA(problem, x0 max_rank);
    CORA::Matrix aligned_soln = problem.alignEstimateToOrigin(soln.first.x);

    std::vector<CORA::Symbol> pose_symbols;
    for (auto const &all_pose_symbols : problem.getPoseSymbolMap()) {
        CORA::Symbol pose_symbol = all_pose_symbols.first;
        pose_symbols.insert(pose_symbol);
    }

    CORA::saveSolnToTum(pose_symbols, problem, aligned_soln, argv[2]);
}