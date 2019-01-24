import _smc

__version__ = '0.0.dev0'

KERN_SUCCESS = 0


def get_temperature(key):
    if _smc.open_smc() != KERN_SUCCESS:
        raise RuntimeError

    temperature = _smc.get_temperature(key)
    _smc.close_smc()

    return temperature
