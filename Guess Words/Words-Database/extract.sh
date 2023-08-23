#!/bin/bash

# Definitions
YELLOW='\033[1m\033[38;2;255;255;0m'
YELLOw='\033[0m\033[38;2;255;255;0m'
GRAY='\033[1m\033[38;2;230;230;230m'
GRAy='\033[0m\033[38;2;230;230;230m'
CYAN='\033[1m\033[38;2;0;230;230m'
GREEN='\033[1m\033[38;2;0;255;0m'
RED='\033[1m\033[38;2;255;0;0m'
RESET='\033[0m '
TAB='   '

# Log Aternatives
TERMINAL="${CYAN}[TERMINAL]${RESET}"
WARNING="${YELLOW}[WARNING]${RESET}"
SUCCESS="${GREEN}[SUCCESS]${RESET}"
FAILED="${RED}[FAILED]${RESET}"
DEV="${YELLOW}[DEV]${RESET}"
LOG="${GRAY}[LOG]${RESET}"

# Source Path to be Extracted from
src_path="$1"

# Destination Path to be Exported into
dst_path="$2"

# Calculate Amount of Words in Persian Language
echo -e "${LOG}Calculating Amount of Words that Can be Extracted"
data=$(cat $src_path | grep -oE "[آ-ی]+")
amount=$(cat $src_path | grep -oE "[آ-ی]+" | wc -l)
echo -e "${TAB}${LOG}Amount : ${CYAN}$amount${RESET}"
echo -e "${LOG}Extracting ${CYAN}$amount${RESET}Words into ${CYAN}$dst_path${RESET}"
if [ -e "$dst_path" ]; then
    rm $dst_path
    touch $dst_path
else
    touch $dst_path
fi
for word in $data; do
  echo "$word" | tee $dst_path
done
# Check Destination File
amount_new=$(cat $dst_path | grep -oE "[آ-ی]+" | wc -l)
if [ "$amount_new" == "$amount" ]; then
    echo -e "${TAB}${SUCCESS}Extracted All Words"
    dst_size=$(du -h $dst_path | awk '{print $1}')
    letters_amount=$(wc -m $dst_path | awk '{print $1}')
    echo -e "${TAB}${TAB}${LOG}Size of File : ${CYAN}$dst_size${RESET}"
    echo -e "${TAB}${TAB}${LOG}Total Amount of Letters : ${CYAN}$letters_amount${RESET}"
else
    echo -e "${TAB}${FAILED}Missed Some Words"
fi