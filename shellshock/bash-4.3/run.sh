#!/bin/sh

echo "-------------"
echo ""
echo "Current bash: "
echo ""
bash -version
echo ""
echo ""
echo "-------------"
echo "Vulnerable bash - 4.3 - shellshock funguje do 4.3"
echo "Prikaz: "
printf '%s'  "env x='() { :;}; echo vulnerable' bash -c \"echo this is a test\""
echo ""
echo ""
./bash -version
env -i PATH="$PWD:$PATH" ./bash --noprofile --norc
