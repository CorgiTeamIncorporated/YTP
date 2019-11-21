#ifndef YDC_MAIN_HPP_
#define YDC_MAIN_HPP_

/// Starts the execution.
///
/// @note SFML takes care of WinMain and other similar issues.
/// @note The status code is platform-specific, but is `0` on success.
///
/// @param argc The amount of the arguments.
/// @param argv The array of the input arguments.
///
/// @return The status code.
int main(int argc, char** argv);

#endif // YDC_MAIN_HPP_
