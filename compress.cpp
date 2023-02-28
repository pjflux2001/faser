#include <bits/stdc++.h>
#include <zlib.h>

#define int long long

using namespace std;

signed main(signed argc, char* argv[]) {
    // Check if 2 operands are present
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // Open the input file
    ifstream input_file(argv[1], ios::binary);
    if (!input_file.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read the input file into a vector
    vector<char> input_data;
    input_file.seekg(0, ios::end);
    input_data.resize(input_file.tellg());
    input_file.seekg(0, ios::beg);
    input_file.read(&input_data[0], input_data.size());
    input_file.close();

    // Compress the input data
    vector<char> output_data(input_data.size());
    uLongf output_size = output_data.size();
    int zlib_result = compress2((Bytef*)(&output_data[0]), &output_size,
                                (const Bytef*)(&input_data[0]), input_data.size(),
                                Z_BEST_COMPRESSION);
    if (zlib_result != Z_OK) {
        cerr << "Error: Unable to compress input data. zlib error code: " << zlib_result << endl;
        return 1;
    }
    output_data.resize(output_size);

    // Calculate compression ratio and print metrics
    double compression_ratio = (double)(input_data.size()) / (double)(output_data.size());
    cout << "Input file size: " << input_data.size() << " bytes" << endl;
    cout << "Output file size: " << output_data.size() << " bytes" << endl;
    cout << "Compression ratio: " << compression_ratio << endl;

    return 0;
}