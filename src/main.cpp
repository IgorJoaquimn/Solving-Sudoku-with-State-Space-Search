#include <string>
#include "BFS.h"
#include "IDS.h"
#include "UCS.h"
#include "A*.h"
#include "GFBS.h"

// Function to parse input Sudoku string and initialize the State object
State parse_input(int argc, char *argv[])
{
    State initial_state;
    for (int i = 2; i < argc; ++i)
        for (int j = 0; j < N; ++j)
            initial_state.state[i - 2][j] = static_cast<uint8_t>(argv[i][j]) - '0';
    return initial_state;
}

int main(int argc, char *argv[])
{
    if (argc != 11)
    {
        std::cerr << "Usage: " << argv[0] << " <algorithm> <sudoku_config>\n";
        return 1;
    }

    std::string algorithm = argv[1];
    std::string sudoku_config = argv[2];

    // Parse input Sudoku configuration
    State initial_state = parse_input(argc, argv);
    Search_Base* search = nullptr;

    switch (algorithm[0]) {
        case 'B':
            search = new BFS(&initial_state);
            break;

        case 'I':
            search = new IDS(&initial_state);
            break;

        case 'U':
            search = new UCS(&initial_state);
            break;

        case 'A':
            search = new A_STAR(&initial_state);
            break;

        case 'G':
            search = new GBFS(&initial_state);
            break;

        default:
            std::cerr << "Invalid algorithm type. Supported types: B, I, U, A, G\n";
            return 1;
    }
    
    State result = search->search();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << char(result.state[i][j] + '0') << " ";
        }
        std::cout << std::endl;
    }

    if (algorithm[0] == 'I')
        std::cout << "lim: " << search->max_lim << std::endl;

    delete search;
    return 0;
}
