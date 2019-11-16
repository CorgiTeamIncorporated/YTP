#ifndef YDC_MAIN_HPP_
#define YDC_MAIN_HPP_

/// Starts the execution.
///
/// @note SFML takes care of WinMain and other similar issues.
///
/// @param argc The amount of the elements in `argv`.
/// @param argv The array of the input arguments.
///
/// @return The status code, platform-specific, but is always `0` on success.
int main(int argc, char** argv);

#endif // YDC_MAIN_HPP_
