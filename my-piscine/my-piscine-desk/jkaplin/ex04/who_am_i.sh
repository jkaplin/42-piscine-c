#!/bin/bash
ldapwhoami | cut -d"," -f1,3-6 | cut -c4-
