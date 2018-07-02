#include "SaveDeflater.h"
/*
#include "BinaryMemoryReader.h"
#include "BinaryMemoryWriter.h"
#include "Chunk.h"
#include "RegionFile.h"
#include "MemoryLeakManager.h"

#include <filesystem>
#include <iomanip>
#include <iostream>

void SaveDeflater::deflate(wxFrame *mainFrame) {
	wxFileDialog *saveLocationDialog = new wxFileDialog(mainFrame,
		wxT("Please navigate to main.ttw inside your desired save folder"),
		wxEmptyString,
		wxEmptyString,
		wxT("main.ttw|main.ttw"),
		wxFD_FILE_MUST_EXIST);
	saveLocationDialog->CenterOnParent();
	int result = saveLocationDialog->ShowModal();
	saveLocationDialog->Close();

	if (wxID_OK == result && "main.ttw" == saveLocationDialog->GetFilename()) {
		std::string pathToRegion = saveLocationDialog->GetPath();
		pathToRegion = pathToRegion.substr(0, pathToRegion.find_last_of('\\') + 1) + "Region";

		int chunkCount = 0;
		for (auto &p : std::experimental::filesystem::directory_iterator(pathToRegion)) {
			++chunkCount;
		}

		chunkCount *= 1024;

		//std::cout << "Deflating save... " << std::endl;

		std::vector<std::vector<unsigned char>> failedChunks;

		int chunksProcessed = 0;

		// Go through each region...
		for (auto &p : std::experimental::filesystem::directory_iterator(pathToRegion)) {
			RegionFile currentFile(p.path().string());

			// Go trough each chunk...
			for (unsigned int i = 0; i < currentFile.zippedChunks.size(); ++i) {
				++chunksProcessed;
				//std::cout << "Processing chunk " << chunksProcessed << "/" << chunkCount << " -> " << std::fixed << std::setprecision(2) << chunksProcessed * 100. / chunkCount << "% done" << std::endl;

				std::vector<unsigned char> originalZipped = currentFile.zippedChunks[i];

				if (currentFile.chunkExists(i)) {
					try {
						std::vector<unsigned char> originalUnzipped;

						BinaryMemoryReader::unzipWhole(currentFile.zippedChunks[i], originalUnzipped);

						Chunk chunk;
						int result = currentFile.readChunk(chunk, i);

						// See if the chunk read was successful...
						if (INT_MAX != result) {
							try {
								BinaryMemoryWriter writer(1000000);
								currentFile.writeChunk(chunk, writer, i);

								std::vector<unsigned char> newUnzipped;
								writer.fetchUnzipped(newUnzipped);

								// See if the chunk write is same as the original...
								if (originalUnzipped.size() == newUnzipped.size()) {
									for (int j = originalUnzipped.size() - 1; j >= 0; --j) {
										if (originalUnzipped[j] != newUnzipped[j]) {
											failedChunks.push_back(originalZipped);
											break;
										}
									}
								}
								else {
									failedChunks.push_back(originalZipped);
								}

								std::vector<unsigned char> newZipped;
								try {
									writer.fetchZipped(newZipped);
								}
								catch (std::ios_base::failure) {
									failedChunks.push_back(originalZipped);
								}
							}
							catch (std::ios_base::failure) {
								failedChunks.push_back(originalZipped);
							}
						}
						else if (INT_MAX == result) {
							failedChunks.push_back(originalZipped);
						}
					}
					catch (std::ios_base::failure) {
						failedChunks.push_back(originalZipped);
					}
				}
			}

			unsigned int k = 0;
			std::vector<RegionFile> generatedFailedRegions;
			while (failedChunks.size() > k * 1024) {
				std::vector<std::vector<unsigned char>> chunkBlock;
				auto start = failedChunks.begin() + k * 1024;
				auto end = failedChunks.size() < (k + 1) * 1024 ? failedChunks.end() : failedChunks.begin() + (k + 1) * 1024;
				chunkBlock = std::vector<std::vector<unsigned char>>(start, end);
				generatedFailedRegions.push_back(RegionFile(std::vector<int>(0), chunkBlock));
				++k;
			}
		}
	}
}
*/
SaveDeflater::SaveDeflater() {}
SaveDeflater::~SaveDeflater() {}

/*SaveDeflaterProgressFrame::SaveDeflaterProgressFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {
	wxPanel *mainPanel = new wxPanel(this);
}
*/
