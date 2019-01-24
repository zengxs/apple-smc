import os
import re
from pathlib import Path

from setuptools import Extension, setup

basedir = Path(os.path.dirname(__file__))

with open(basedir / 'smc' / '__init__.py') as smc_file:
    m = re.findall(r'__version__\s*=\s*[\'"](.*)[\'"]', smc_file.read())
    version = m[0]

setup(
    name='apple-smc',
    version=version,
    ext_modules=[
        Extension(
            name='_smc',
            sources=['module/smc.c', 'module/smc-wrapper.c'],
            extra_link_args=['-framework', 'IOKit'],
        ),
    ],
)
